Last login: Fri Apr 25 09:49:58 on console
(base) macbookpro@macbookriaangel ~ % screen -S mongodb-install 






















Uncaught:
SyntaxError: Unexpected token, expected "," (1:26)

> 1 | db.person.insertOne("name":"john"})
    |                           ^
  2 |

stident> db.person.inserOne("name":"john"}
Uncaught:
SyntaxError: Unexpected token, expected "," (1:25)

> 1 | db.person.inserOne("name":"john"}
    |                          ^
  2 |

stident> db.person.insertOne({ "name": "john" })
{
  acknowledged: true,
  insertedId: ObjectId('6814ca9a2404d838f67369cd')
}
stident> db.person.find()
[ { _id: ObjectId('6814ca9a2404d838f67369cd'), name: 'john' } ]
stident> 

