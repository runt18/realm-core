// @@Example: ex_cpp_typed_query_group @@
// @@Fold@@
#include <tightdb.hpp>

TIGHTDB_TABLE_2(PeopleTable,
                name, String,
                age, Int)

void main()
{
    PeopleTable table;

// @@EndFold@@
    table.add("Mary",  14);  // Match
    table.add("Joe",   17);  // Match
    table.add("Jack",  22);      
    table.add("Bob",   80);       
    table.add("Alice", 71);  // Match

    // Find rows where (age > 12 && age < 20) || name == "Alice"
    PeopleTable::Query query = table.where().group()
                                                .age.greater(12)
                                                .age.less(20)
                                            .end_group()
                                            .Or()
                                            .name.equal("Alice");

    PeopleTable::View view = query.find_all();
// @@Fold@@
    // Expected result
    assert(view.size() == 3);
    assert(!strcmp(view[0].name, "Mary"));
    assert(!strcmp(view[1].name, "Joe"));
    assert(!strcmp(view[2].name, "Alice"));
}
// @@EndFold@@
// @@EndExample@@
