params [
	["_from_pid", "", [""]],
	["_to_pid", "", [""]],
	["_details", "", [""]],
	["_emet", "", [""]],
	["_price", -1, [0]],
	["_name_from", "", [""]],
	["_name_to", "", [""]]
];
if ((_from_pid isEqualTo "") || (_to_pid isEqualTo "") || (_name_from isEqualTo "")|| (_name_to isEqualTo "")|| (_details isEqualTo "") || (_emet isEqualTo "") || (_price isEqualTo -1)) exitWith {};
private _date = systemTime;
private _text = format['%1/%2/%3 %4:%5',( _date # 2), (_date # 1), (_date # 0), ( _date # 3), ( _date # 4)];
_query = format ["INSERT INTO factures (from_uid, to_uid, name_from, name_to, details, price, create_date) VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7')",
_from_pid,
_to_pid,
_name_from,
_name_to,
_details,
[_price] call DB_fnc_numberSafe,
_text];
[_query,1] call DB_fnc_asyncCall;

