#include <UnitTest++/UnitTest++.h>
#include <iostream>
#include "TableCipher.hpp"
#include <locale>
#include <codecvt>
using namespace std;

string for_encrypt (int key, string word)
{
    TableCipher c{key};
    string s = c.encrypt(word);
    const string s2 (s.begin(), s.end() );
    return s2;
}

string for_decrypt (int key, string word)
{
    TableCipher c{key};
    string s = c.decrypt(word);
    const string s2 (s.begin(), s.end() );
    return s2;
}


SUITE (KeyTest)
{
    string test = "СОЦИАЛЬНОСТЬ";
    int k;
    TEST (ValidKey) {
        CHECK_EQUAL(for_encrypt(k=4,test),"ЬНИТЬЦСЛООАС");
    }
    
    TEST(EmptyKey) {
        CHECK_THROW(for_encrypt(k=0,test), cipher_error);
    }
    TEST(NegativeKey) {
        CHECK_THROW(for_encrypt(k=-5,test), cipher_error);
    }
    TEST(LargeKey) {
        CHECK_THROW(for_encrypt(k=55,test), cipher_error);
    }
}

SUITE(EncryptTest)
{
    TEST(ValidText) {
        CHECK_EQUAL(for_encrypt(4,"ЯБАКУГАН"),"НКААГБУЯ");
    }
    TEST(LowText) {
        CHECK_EQUAL(for_encrypt(4,"ЯбаКуГан"),"нКааГбуЯ");
    }
    TEST(EmptyText) {
        CHECK_THROW(for_encrypt(1," "),cipher_error);
    }
    TEST(ValiDTextWithoutletters) {
        CHECK_THROW(for_encrypt(1,".127"),cipher_error);
    }
    TEST(TextWithNumber) {
        CHECK_THROW(for_encrypt(4,"ЖИЭ33"),cipher_error);
    }
    TEST(TextWithSpaceAndPunct) {
        CHECK_THROW(for_encrypt(6,"ПрПрПр!"),cipher_error);
    }
}

SUITE(DecryptText)
{
    TEST(ValidTEXT) {
        CHECK_EQUAL(for_decrypt(4,"НКААГБУЯ"),"ЯБАКУГАН");
    }
    TEST(LowTEXT) {
        CHECK_EQUAL(for_decrypt(4,"нКааГбуЯ"),"ЯбаКуГан");
    }
    TEST(EmptyTEXT) {
        CHECK_THROW(for_decrypt(4," "),cipher_error);
    }
    TEST(TextNumberText) {
        CHECK_THROW(for_decrypt(4,"ЖИЭ33"),cipher_error);
    }
    TEST(TextSymbolText) {
        CHECK_THROW(for_decrypt(4,"ПрПрПр!"),cipher_error);
    }

}
int main()
{
    return UnitTest::RunAllTests();
}