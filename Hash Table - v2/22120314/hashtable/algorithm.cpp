#include "hashtable.h"
#include <iostream>
#include <fstream>
#include <sstream>


const int TABLE_SIZE = 5000;
const int P = 31;
const int M = 1000000009 ;

void PrintCompany(Company company)
{
    cout << "Name: " << company.name << "\t Profit Tax: " << company.profit_tax << "\t Address: " << company.address << endl;
}

vector<Company> ReadListCompany(string file_name)
{
    vector<Company> companies;
    ifstream file(file_name);

    if (!file.is_open())
    {
        cerr << "Khong the mo file: " << file_name << std::endl;
        return companies;
    }

    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        Company company;

        if (getline(iss, company.name, '|') &&
            getline(iss, company.profit_tax, '|') &&
            getline(iss, company.address))
        {
            companies.push_back(company);
        }
        else
        {
            cerr << "Loi khi doc dong: " << line << std::endl;
        }
    }

    file.close();
    return companies;
}

Company Search( Company* hash_table,string company_name)
{
    int index = HashString(company_name) % TABLE_SIZE;
    int i = 0;
    while (!hash_table[(index + i * i) % TABLE_SIZE].name.empty())
    {
        if (hash_table[(index + i * i) % TABLE_SIZE].name == company_name)
        {
            return hash_table[(index + i * i) % TABLE_SIZE];
        }
        i++;
    }

    return Company{ "", "", "" };
}
    
long long ModPow(long long base, long long exponent, long long mod)
{
    if (exponent == 0)
        return 1;

    long long half_pow = ModPow(base, exponent / 2, mod);
    long long result = (half_pow * half_pow) % mod;

    if (exponent % 2 == 1)
        result = (result * base) % mod;

    return result;
}

int HashString(string company_name)
{
    string s;
    if (company_name.length() >= 20) {
        s = company_name.substr(company_name.length() - 20);
    }
    else {
        s = company_name;
    }

    long long hash_value = 0;

    for (int i = 0; i < s.length(); ++i)
    {
        hash_value = (hash_value + (s[i] * ModPow(P, i, M)) % M) % M;
    }

    return static_cast<int>(hash_value);
}

Company* CreateHashTable(vector<Company> list_company)
{
    Company* hash_table = new Company[TABLE_SIZE]();

    for (vector<Company>::size_type i = 0; i < list_company.size(); i++)
    {
        int index = HashString(list_company[i].name) % TABLE_SIZE;
        if (index < TABLE_SIZE)
        {
            Insert(hash_table, list_company[i]);
        }
    }
    return hash_table;
}

void Insert(Company* hash_table, Company company)
{
    int index = HashString(company.name) % TABLE_SIZE;
    if (hash_table[index].name.empty())
    {
        hash_table[index] = company;
    }
    else
    {
        int i = 1;
        while (!hash_table[(index + i * i) % TABLE_SIZE].name.empty())
        {
            i++;
        }
        hash_table[(index + i * i) % TABLE_SIZE] = company;
    }
}
