#include "doctest.h"
#include "FamilyTree.hpp"

using namespace family;

#include <string>
using namespace std;

TEST_CASE("Test 1 addFather & addMother & relation") {

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

    //check case of searching name that doesn't exist on the tree 
    CHECK(T.relation("Hila") == string("unrelated"));
    CHECK(T.relation("Ben") == string("unrelated"));
    CHECK(T.relation("Eva") == string("unrelated"));
    CHECK(T.relation("Shimon") == string("unrelated"));
    CHECK(T.relation("Yossi") == string("unrelated"));
}

TEST_CASE("Test 1 find") {

    Tree T ("Yonit");
    T.addFather("Yonit", "Arel").addMother("Yonit", "Ronit")
     .addFather("Ronit", "Yonatan").addMother("Ronit", "Simha")
     .addFather("Arel", "Yosef").addMother("Arel", "Dikla");

    CHECK(T.find("mother") == string("Ronit"));
    CHECK(T.find("father") == string("Arel"));
    CHECK((T.find("grandfather") == string("Yosef") || T.find("grandfather") == string("Yonatan")));
    CHECK((T.find("grandmother") == string("Simha") || T.find("grandmother") == string("Dikla")));
    CHECK_THROWS(T.find("uncle")); //there is no option of "uncle" on this tree
    CHECK_THROWS(T.find("sister"));
    CHECK_THROWS(T.find("great-grandfather")); //there is no great-grandfather here
    CHECK_THROWS(T.find("great-grandmother"));
    
    T.addMother("Yosef", "Efrat").addFather("Yosef", "Shmuel").addFather("Shmuel", "Israel");

    CHECK(T.find("grandmother") == string("Efrat"));
    CHECK(T.find("grandfather") == string("Shmuel"));
    CHECK(T.find("great-grandfather") == string("Israel"));
    CHECK_THROWS(T.find("great-grandmother"));

    T.addFather("Yonatan", "Ofer").addMother("Yonatan", "Sima").addMother("Simha", "Ester"); 

    CHECK((T.find("grandfather") == string("Shmuel") || T.find("grandfather") == string("Ofer"))); 
    CHECK((T.find("grandmother") == string("Efrat") 
        || T.find("grandmother") == string("Sima")
        || T.find("grandmother") == string("Ester"))); 
    CHECK_THROWS(T.find("great-great-grandfather"));
}

TEST_CASE("Test 1 remove") {

    Tree T ("Maya");
    T.addMother("Maya", "Anat").addFather("Maya", "Rami")
     .addMother("Anat", "Rivka").addFather("Anat", "Yoni")
     .addMother("Yoni", "Vered").addFather("Yoni", "Shlomi")
     .addFather("Rami", "David");

    CHECK_THROWS(T.remove("Maya")); //try to remove the root --> exception

    CHECK((T.find("grandfather") == string("David") || T.find("grandfather") == string("Yoni")));

    CHECK(T.find("father") == string("Rami"));
    T.remove("Rami"); 
    CHECK_THROWS(T.find("father"));
    CHECK(T.find("grandfather") == string("Yoni")); //because David has removed from the tree while removing Rami

    CHECK(T.find("great-grandmother") == string("Vered")); 
    CHECK(T.find("great-grandfather") == string("Shlomi")); 
    T.remove("Vered");
    CHECK_THROWS(T.find("great-grandmother"));
    T.remove("Yoni");
    CHECK_THROWS(T.find("great-grandfather"));
    CHECK_THROWS(T.find(T.find("grandfather")));

    T.addFather("Anat", "Nir"); //we've removed Yoni, sowe can add new father to Anat now
    CHECK(T.find("grandfather") == string("Nir")); 
    CHECK(T.find("grandmother") == string("Rivka"));
    T.remove("Rivka"); 
    CHECK_THROWS(T.find("grandmother")); 
    T.remove("Anat"); 
    CHECK_THROWS(T.find("grandfather")); 
    CHECK_THROWS(T.find("mother"));
}

TEST_CASE("Test 2 addFather & addMother & relation"){}

TEST_CASE("Test 2 find"){}

TEST_CASE("Test 2 remove"){}