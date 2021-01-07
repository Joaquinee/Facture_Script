params ["_selectedIndex"];
disableSerialization;
private _listBox = (findDisplay 040116) displayCtrl 040117;
private _text = (findDisplay 040116) displayCtrl 040118;
private _data = _listBox lbData _selectedIndex;
_data = call compile format ["%1", _data];
private _price = _data # 2;
if (life_atmbank < _price) exitWith {
	hint "Vous n'avez pas assez d'argent sur votre compte en banque pour payer cette facture";
};
life_atmbank = life_atmbank - _price;
[1] call SOCK_fnc_updatePartial;
[(_data # 3), 0] remoteExec ["fac_serv_fnc_updateFacture",2];
{ctrlShow [_x, false];} forEach  [040119, 040120];
hint parseText format ["Vous venez de payer une facture de : %1 €<br /> A : %2", _price, (_data # 0)];

private _to = objNull;
{
	if (!(isNull _x) && (alive _x) && ((getPlayerUID _x) isEqualTo ((_data # 5)))) then {
		_to = _x;
	};
		
} forEach playableUnits;

if (!(isNull _to)) then {

	[player, _price, "Payer"] remoteExec ["fac_fnc_receivedEmit", _to];	
} else {
	[_price, (_data # 5)] remoteExec ["fac_serv_fnc_updateBanque",2];
};


private _arr = uiNamespace getVariable ["ItemsList", []];
private _idx = _arr findIf {(_x # 3) isEqualTo (_data # 3)}; 
_listBox lbDelete _selectedIndex;
_arr deleteAt _idx;
_text ctrlSetStructuredText parseText "";