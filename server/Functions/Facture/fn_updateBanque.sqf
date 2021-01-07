params ["_price", "_uid"];

private _current = format ["SELECT bankacc, cash FROM players WHERE pid='%1'", _uid];
private _result = [_current,2,true] call DB_fnc_asyncCall;
private _money =  (_result # 0) # 0;
private _new = _money + _price;
_query = format ["UPDATE players SET bankacc='%1' WHERE pid='%2'",[_new] call DB_fnc_numberSafe,_uid];
[_query,1] call DB_fnc_asyncCall;