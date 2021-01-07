params ["_display", "_type"];
if (_type isEqualto 3) exitWith {
	[[],_type,_display] spawn fac_fnc_loadDialog;
};
[getPlayerUID player, _type, _display] remoteExec ["fac_serv_fnc_getFacture", 2];





