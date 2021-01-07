params ["_ctrl", "_list", "_text"];
disableSerialization;
private _listBox = (ctrlParent _ctrl) displayCtrl _list;
private _text = (ctrlParent _ctrl) displayCtrl _text;
_text ctrlSetStructuredText parseText "";
private _array = uiNamespace getVariable ["ItemsList", []];
lbClear _listBox;
{
    if (toLower(ctrlText _ctrl) in toLower(_x # 0)) then {
        _listBox lbAdd format['%1', (_x # 0)];
        _listBox lbSetData[(lbSize _listBox)-1, str(_x)];
        switch(_x # 4) do {
			case 0: {_listBox lbSetColor [(lbSize _listBox)-1,[0,0.66,0.11,1]]};
			case 2: {_listBox lbSetColor [(lbSize _listBox)-1,[1,0,0,1]]};
		};
    };
} forEach _array;
