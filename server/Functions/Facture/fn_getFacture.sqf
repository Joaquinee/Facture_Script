params ["_pid", "_type", "_display"];
_query = format ["SELECT from_uid, name_from, name_to, details, price, payed, create_date, payed_date, id FROM factures WHERE to_uid='%1' ORDER BY id DESC", _pid];
_result = [_query,2,true] call DB_fnc_asyncCall;
private _arr = [];
switch (_type) do {
	case 0: {
		{
			if((_x # 5) isEqualTo 1) then {
			// Name - Details - Price - id - create_date
			_arr pushBack [(_x # 1), (_x # 3), (_x # 4),(_x # 8), (_x # 6), (_x # 0)];
			};
		} forEach _result;
	};
	case 1: {
		{
			//Name - Details - Price - id -  Payed - payed_date - created_date
			if((_x # 5) in [0,2]) then {
				_arr pushBack [(_x # 1), (_x # 3), (_x # 4),(_x # 8),(_x # 5),(_x # 6),(_x # 7)];
			};
		} forEach _result;
	};
	case 2: {
		_queryTwo = format ["SELECT name_to, details, price, id, payed, create_date, payed_date FROM factures WHERE from_uid='%1' ORDER BY id DESC", _pid];
		_resultTwo = [_queryTwo,2,true] call DB_fnc_asyncCall;
		_arr = _resultTwo;
	};
};
[_arr,_type,_display] remoteExec ["fac_fnc_loadDialog", remoteExecutedOwner];