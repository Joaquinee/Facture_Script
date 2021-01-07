params ["_result", "_type", "_diag"];
disableSerialization;
private _display = findDisplay (_diag # 0);
private _listBox = _display displayCtrl (_diag # 1);
uiNamespace setVariable ["display", _display];
lbClear _listBox;
switch (_type) do {
	case 0: {
		{
			_listBox lbAdd format['%1', (_x # 0)];
			_listBox lbSetData[(lbSize _listBox)-1, str(_x)];
		} forEach _result;
	};
	case 1 : {
		{
			_listBox lbAdd format['%1', (_x # 0)];
			_listBox lbSetData[(lbSize _listBox)-1, str(_x)];
			switch(_x # 4) do {
				case 0: {_listBox lbSetColor [(lbSize _listBox)-1,[0,0.66,0.11,1]]};
				case 2: {_listBox lbSetColor [(lbSize _listBox)-1,[1,0,0,1]]};
			};
		} forEach _result;
	};
	case 2 : {
		{
			_listBox lbAdd format['%1', (_x # 0)];
			_listBox lbSetData[(lbSize _listBox)-1, str(_x)];
			switch(_x # 4) do {
				case 0: {_listBox lbSetColor [(lbSize _listBox)-1,[0,0.66,0.11,1]]};
				case 1: {_listBox lbSetColor [(lbSize _listBox)-1,[1,0.55,0,1]]};
				case 2: {_listBox lbSetColor [(lbSize _listBox)-1,[1,0,0,1]]};
			};
		} forEach _result;
	};
	case 3 : {
		{
			if (!(isNull _x) && (alive _x) && !(_x isEqualTo player)) then {
				_listBox lbAdd format ["%1", _x getVariable ["realname",name _x]];
				_listBox lbSetdata [(lbSize _listBox)-1,str(_x)];
			};
		} forEach playableUnits;

		private _edit = _display displayCtrl 05012044;
		_edit ctrlSetText format["%1", name player];

	};
};
uiNamespace setVariable ["ItemsList", _result];