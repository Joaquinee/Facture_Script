params ["_selectedIndex"];
disableSerialization;
private _listBox = (findDisplay 040116) displayCtrl 040117;
private _text = (findDisplay 040116) displayCtrl 040118;
private _data = _listBox lbData _selectedIndex;
_data = call compile format ["%1", _data];
private _price = _data # 2;
[(_data # 3), 2] remoteExec ["fac_serv_fnc_updateFacture",2];
{ctrlShow [_x, false];} forEach  [040119, 040120];
hint parseText format ["Vous venez de refuser une facture de : %1 €<br /> Pour : %2", _price, (_data # 0)];
private _to = objNull;
{
	if (!(isNull _x) && (alive _x) && ((getPlayerUID _x) isEqualTo ((_data # 5)))) then {
		_to = _x;
	};
		
} forEach playableUnits;

if (!(isNull _to)) then {
	[player, _price, "Refuser"] remoteExec ["fac_fnc_receivedEmit", _to];	
};
private _arr = uiNamespace getVariable ["ItemsList", []];
private _idx = _arr findIf {(_x # 3) isEqualTo (_data # 3)}; 
_listBox lbDelete _selectedIndex;
_arr deleteAt _idx;
_text ctrlSetStructuredText parseText "";