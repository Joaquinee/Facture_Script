params ["_from", "_price", "_text"];
hint format ["%1 viens de %2 la facture de %3€", _from getVariable "realname", _text, _price];
if (_text isEqualTo "Payer") then {
	life_atmbank = life_atmbank + _price;
	[1] call SOCK_fnc_updatePartial;
};

