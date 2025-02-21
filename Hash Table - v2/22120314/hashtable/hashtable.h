#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include <vector>

using namespace std;

struct Company
{
    string name;
    string profit_tax;
    string address;
};

vector<Company> ReadListCompany(string file_name);
int HashString(string company_name);
Company* CreateHashTable(vector<Company> list_company);
void Insert(Company* hash_table,Company company);
Company Search(Company* hash_table,string company_name);
void PrintCompany(Company company);

#endif // COMPANY_H
