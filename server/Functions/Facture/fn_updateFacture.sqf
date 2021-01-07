params [
	["_id", -1, [0]],
	["_state",-1,[0]]
];
private _date = systemTime;
private _text = format['%1/%2/%3 %4:%5',( _date # 2), (_date # 1), (_date # 0), ( _date # 3), ( _date # 4)];
_id = [_id] call DB_fnc_numberSafe;
_state = [_state] call DB_fnc_numberSafe;
_query = format ["UPDATE factures SET payed='%1', payed_date='%2' WHERE id='%3'",_state,_text,_id];
[_query,1] call DB_fnc_asyncCall;
