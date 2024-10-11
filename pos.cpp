#include <iostream>
#include <vector>

using namespace std;

class Product
{
public:
    string product_name;
    int stock;
    float harga_jual;

    Product(string product_name, int stock, float harga_jual)
    {
        this->product_name = product_name;
        this->stock = stock;
        this->harga_jual = harga_jual;
    }

    void ShowData() const
    {
        cout << "Nama Product : " << this->product_name << endl;
        cout << "Stock Product : " << this->stock << endl;
        cout << "Harga Product : " << this->harga_jual << endl;
        cout << endl;
    }
};

class Transaksi
{
public:
    string product_name;
    int quantity;
    float total_harga;
    Transaksi(string product_name, int quantity, float total_harga)
    {
        this->product_name = product_name;
        this->quantity = quantity;
        this->total_harga = total_harga;
    }

    void ShowData() const
    {
        cout << "Nama Product : " << this->product_name << endl;
        cout << "Quantity : " << this->quantity << endl;
        cout << "Total Harga : " << this->total_harga << endl;
        cout << endl;
    }
};

//  ? Product Function
void ListProduct(vector<Product> &products)
{
    for (int i = 0; i < products.size(); i++)
    {
        cout << i + 1 << '.' << endl;
        products[i].ShowData();
    }
}
// ? Transaksi Function
void ListTransaksi(vector<Transaksi> &transaksis)
{
    for (int i = 0; i < transaksis.size(); i++)
    {
        cout << i + 1 << '.' << endl;
        transaksis[i].ShowData();
    }
}

int main()
{
    //  ? System
    string inpSys;
    int Pilihan;
    bool sysku = true;

    // ? Product
    vector<Product>::size_type indexEdit, indexDelete;
    string name;
    float price;
    int stock;
    // ? Transaksi
    vector<Transaksi>::size_type indexTransaksiProduct;
    int quantity;

    vector<Product> products;
    products.emplace_back("Test Product 1", 5, 12000.0);
    products.emplace_back("Test Product 2", 5, 12000.0);
    products.emplace_back("Test Product 3", 5, 12000.0);

    vector<Transaksi> transaksis;

    while (sysku)
    {
        cout << endl;
        cout << "1. List Product" << endl;
        cout << "2. Tambah Product" << endl;
        cout << "3. Edit Product" << endl;
        cout << "4. Delete Product" << endl;

        cout << "5. List Transaksi" << endl;
        cout << "6. Penjualan" << endl;
        cout << "Masukan Nomor Pilihan : ";
        cin >> Pilihan;

        switch (Pilihan)
        {
        case 1:
            ListProduct(products);
            break;
        case 2:
            cin.ignore();
            cout << "Masukan Nama Product : ";
            getline(cin, name);

            cout << "Masukan Stock Product : ";
            cin >> stock;

            cout << "Masukan Harga Product : ";
            cin >> price;

            products.emplace_back(name, stock, price);

            name = "";
            stock = 0;
            price = 0;

            cout << endl;
            cout << "Berhasil Di Create" << endl;
            break;
        case 3:
            cout << products.size() << endl;
            ListProduct(products);
            cout << "Masukan Nomor yang Ingin Di edit : ";
            cin >> indexEdit;

            if (indexEdit - 1 > products.size() || indexEdit < 0)
            {
                cout << "Nomor Product Tidak Ada" << endl;
                break;
            }

            cin.ignore();
            cout << "Masukan Nama Product : ";
            getline(cin, name);

            cout << "Masukan Stock Product : ";
            cin >> stock;
            cout << "Masukan Harga Product : ";
            cin >> price;

            products[indexEdit - 1].product_name = name;
            products[indexEdit - 1].stock = stock;
            products[indexEdit - 1].harga_jual = price;

            name = "";
            stock = 0;
            price = 0;
            cout << endl;
            cout << "Berhasil Di Update" << endl;
            ;
            break;

        case 4:
            cout << products.size() << endl;
            ListProduct(products);

            cout << "Masukan Nomor yang Ingin Di Delete : ";
            cin >> indexDelete;

            if (indexDelete - 1 > products.size() || indexDelete < 0)
            {
                cout << "Nomor Product Tidak Ada" << endl;
                break;
            }
            products.erase(products.begin() + indexDelete);
            cout << endl;
            cout << "Berhasil Di Hapus" << endl;
            ;
            break;

        case 5:
            ListTransaksi(transaksis);
            break;

        case 6:
            cout << "Masukan List Product : ";
            cin >> indexTransaksiProduct;

            if (indexTransaksiProduct - 1 > products.size() || indexTransaksiProduct < 0)
            {
                cout << "Nomor Product Tidak Ada" << endl;
                break;
            }

            cout << "Masukan Quantity : ";
            cin >> quantity;
            if (products[indexTransaksiProduct - 1].stock - quantity)
            {
                cout << "Stock tidak mencukupi" << endl;
                break;
            }
            products[indexTransaksiProduct - 1].stock = products[indexTransaksiProduct - 1].stock - quantity;
            transaksis.emplace_back(products[indexTransaksiProduct - 1].product_name, quantity, products[indexTransaksiProduct - 1].harga_jual * quantity);
            quantity = 0;
            cout << endl;
            cout << "Transaksi Berhasil" << endl;
            break;

        default:
            cout << "Nomor Tidak Ada Di List" << endl;
        }

        cout << "Apakah Ingin Melanjutkan y/n: ";
        cin >> inpSys;
        inpSys == "y" ? sysku = true : sysku = false;
    }

    cout << "Program Sudah Selesai !!!";
    return 0;
}