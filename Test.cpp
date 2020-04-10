#include "doctest.h"
#include "FamilyTree.hpp"

using namespace family;

#include <string>
using namespace std;

TEST_CASE("Test addFather & addMother & relation") {

    Tree T ("Shalom");
    T.addFather("Shalom", "Aharon").addMother("Shalom", "Yafa");

    CHECK(T.relation("Shalom") == string("me"));
    CHECK(T.relation("Aharon") == string("father"));
    CHECK(T.relation("Yafa") == string("mother"));
    CHECK_THROWS(T.addFather("Shalom", "Yosef")); //Shalom already has a father
    CHECK_THROWS(T.addMother("Shalom", "Meri"));

    T.addMother("Yafa", "Ahuva").addMother("Ahuva", "Miriam");

    CHECK(T.relation("Ahuva") == string("grandmother"));
    CHECK(T.relation("Miriam") == string("great-grandmother"));
    CHECK_THROWS(T.addMother("Yafa", "Michal"));
    CHECK_THROWS(T.addMother("Ahuva", "Michal"));
    CHECK_THROWS(T.addFather("Sason", "Yaakov")); //Sason is not on the tree

    T.addFather("Yafa", "Avi").addFather("Aharon", "Yigal").addMother("Aharon", "Nira");

    CHECK(T.relation("Avi") == string("grandfather"));
    CHECK(T.relation("Yigal") == string("grandfather"));
    CHECK(T.relation("Nira") == string("grandmother"));
    CHECK_THROWS(T.addFather("Yafa", "Yishai"));
    CHECK_THROWS(T.addMother("Aharon", "Tzila"));
}

TEST_CASE("Test find") {

    Tree T ("Yonit");
    T.addFather("Yonit", "Arel").addMother("Yonit", "Ronit")
     .addFather("Ronit", "Yonatan").addMother("Ronit", "Simha")
     .addFather("Arel", "Yosef").addMother("Arel", "Dikla");
}