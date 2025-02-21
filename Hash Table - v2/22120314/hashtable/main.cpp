#include "hashtable.h"
#include <iostream>


void PrintHashTable(Company* hash_table)
{
    cout << "Hash Table:" <<endl;

    for (int i = 0; i < 5000; ++i)
    {
        if (!hash_table[i].name.empty())
        {
            cout << "Index " << i << ": " << hash_table[i].name << " - " << hash_table[i].profit_tax << " - " << hash_table[i].address <<endl;
        }
        else
        {
            cout << "Index " << i << ": Empty" << endl;
        }
    }
}
int main()
{
    string file_name = "D:/DSA/TH DSA/Hash Table/MST.txt";
    vector<Company> companies = ReadListCompany(file_name);
  
    Company* hash_table = CreateHashTable(companies);
    // Ví dụ tìm kiếm thông tin nhiều công ty
    cout << " ------------------------------------" << endl;
    vector<string> search_company_names = { "CONG TY TNHH BEE VIET NAM", "CONG TY TNHH NONG NGHIEP CONG NGHE CAO MIEN DONG VIET", "CONG TY ABC" ,"CONG TY TNHH EAGLE PAPER CORP","aSDasdas"};

    for (const auto& search_company_name : search_company_names)
    {
        Company result = Search(hash_table, search_company_name);

        cout << "Ket qua tim kiem cho cong ty '" << search_company_name << "':" << endl;
        if (result.name.empty())
        {
            cout << "Khong tim thay thong tin cong ty." << endl;
        }
        else
        {
            PrintCompany(result);
        }
        cout << endl;
    }

    // Giải phóng bộ nhớ
    delete[] hash_table;

    return 0;
}
