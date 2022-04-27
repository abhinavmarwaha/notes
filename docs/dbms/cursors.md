# Cursors

* temp mem or temp Work Station.
* allocated by server at DML by user.
* store db.

1. implicit - server
2. explicit - user

```
DECLARE s1 CURSOR FOR SELECT * FROM studDetails

OPEN s1

FETCH FIRST FROM s1
FETCH LAST FROM s1
FETCH NEXT FROM s1
FETCH PRIOR FROM s1
FETCH ABSOLUTE 7 FROM s1
FETCH RELATIVE -2 FROM s1

CLOSE s1

DEALLOCATE s1
```