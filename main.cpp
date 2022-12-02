#include <bits/stdc++.h>
using namespace std;

int str_to_int(string str) ///Converts String into Integer
{
    int num = 0;
    for(int i = str.length()-1, j = 0 ; i > -1 && j < str.length() ; i--, j++)
    {
        num += pow(10, i) * (str[j]-48);
    }
    return num;
}
//-------------------------------------------------------------------------------
int XOR(int num1, int num2) /// XOR between two Integers
{
    int result = 0;
    result = (num1+num2)%2;
    return result;
}

deque<int> XOR_key(deque<int>d1, deque<int>d2) /// XOR between two Deques
{
    deque<int> result;
    int d1Size = d1.size();

    for(int i = 0 ; i < d1Size ; i++)
    {
        result.push_back((d1[i]+d2[i])%2);
    }
    return result;
}
//-------------------------------------------------------------------------------
deque<int> text_toBinary(string const &str)
{
    deque<int> binary;
    for (int i=0; i<8; i++)
    {
        string b = bitset<8>(str[i]).to_string();
        for(int j=0; j<8; j++)
        {
            binary.push_back(b[j]-48);
        }
    }
    return binary;
}
//-------------------------------------------------------------------------------
int BinaryToDecimal(deque<int> bin)///Convert Binary Deque form into Decimal Form
{
    int decimal = 0, length = bin.size();
    for(int i = 0 ; i < length  ; i++)// 0 1 1 =3
    {
        if(bin[i] == 1)
        {
            //3   - 2-1
            decimal+=pow(2, (length-i-1));
        }
    }
//    cout<<"decimal:"<<decimal<<endl;
    return decimal;
}
//Overriding
int BinaryToDecimal(string bin)///Convert Binary "String form" into Decimal Form
{
    int decimal = 0, length = 0;
    int int_bin = str_to_int(bin);
    while(int_bin > 0)
    {
        int_bin/=10;
        length++;
    }
    int_bin = str_to_int(bin);
    for(int i = 0 ; i < length  ; i++)
    {
        if(int_bin %10 == 1)
        {
            decimal+=pow(2, i);
            int_bin/=10;
        }
        else
        {
            int_bin/=10;
            continue;
        }
    }
    return decimal;
}
//-------------------------------------------------------------------------------
string BinarytoASCII(deque<int> str) ///Converting the Binary form of strings to its ASCII Form
{
    int N = int(str.size());

    string res = "";
    deque<int> str1 ;

    for (int i = 0; i <= N; i++)
    {
        if(i%8==0 && i!=0)
        {
            int decimal_value= BinaryToDecimal(str1);
            res += char(decimal_value);

            str1.clear();
            str1.push_back(str[i]-48);
        }
        else
        {
            str1.push_back(str[i]);
        }

    }
    return res;
}
//-------------------------------------------------------------------------------
deque<int> DecimalToBinary(int decimal, int no_of_bits)///Convert Decimal form into Binary Form by Setting the no. of bit representation
{
    //int binary = 0;
    deque<int>dq_binary;
    string str_bin = "";
    for(int i = (no_of_bits-1) ; i > -1 ; i--)
    {
        if(decimal >= pow(2,i) )
        {
            str_bin+="1";
            decimal -= pow(2,i);
        }
        else
        {
            str_bin+="0";
        }
    }
    for(int i = 0 ; i < no_of_bits ; i++)//pushing the answer in a deque
    {
        dq_binary.push_back(str_bin[i]-48);
    }
    //////////////////////
//        for(auto it=dq_binary.begin(); it!=dq_binary.end(); it++)//printing deque
//        {
//            cout<<"DecimalToBinary: ";
//            cout << *it << " ";
//        }
//        cout<<endl;
    //////////////////////
    return dq_binary;
}
//-------------------------------------------------------------------------------
deque<int> diffusion(deque<int> table, deque<int> input) ///Used inside any function deals with tables
{
    deque<int> output;
    for(int i=0; i<table.size(); i++)
    {
        output.push_back(input[table[i]-1]);
        //output[table[i]-1]=input[i];
    }
    return output;
}
//-------------------------------------------------------------------------------
deque<int> IP (deque<int> plain)///IP&IP_inverse Functions
{
    deque<int> permutation_table =
    {
        58,50,42,34,26,18,10,2
        ,60,52,44,36,28,20,12,4
        ,62,54,46,38,30,22,14,6
        ,64,56,48,40,32,24,16,8
        ,57,49,41,33,25,17,9,1
        ,59,51,43,35,27,19,11,3
        ,61,53,45,37,29,21,13,5
        ,63,55,47,39,31,23,15,7
    };
    return diffusion(permutation_table, plain);
}

deque<int> IP_inverse (deque<int> plain)
{
    deque<int> permutation_inverse_table =
    {
        40,8,48,16,56,24,64,32
        ,39,7,47,15,55,23,63,31
        ,38,6,46,14,54,22,62,30
        ,37,5,45,13,53,21,61,29
        ,36,4,44,12,52,20,60,28
        ,35,3,43,11,51,19,59,27
        ,34,2,42,10,50,18,58,26
        ,33,1,41,9,49,17,57,25
    };
    return diffusion(permutation_inverse_table, plain);
}
//-------------------------------------------------------------------------------
///Steps of the F_Function
deque<int> Expansion (deque<int> R)///Expansion E
{
    deque<int> Expansion_table =
    {
        32, 1, 2, 3, 4, 5
        ,  4, 5, 6, 7, 8, 9
        ,  8, 9,10,11,12,13
        ,12,13,14,15,16,17
        ,16,17,18,19,20,21
        ,20,21,22,23,24,25
        ,24,25,26,27,28,29
        ,28,29,30,31,32, 1
    };
    return diffusion(Expansion_table, R);
}
//-------------------------------------------------------------------------------
deque<int> S_Box_1(int row, int column)///S-Boxes
{
    int decimal = 0;
    int S_Box_1[4][16] =
    {
        {14,04,13,01,02,15,11,8,03,10,06,12,05,9,00,07}
        , {00,15,07,04,14,02,13,01,10,06,12,11,9,05,03,8}
        , {04,01,14,8,13,06,02,11,15,12,9,07,03,10,05,00}
        , {15,12,8,02,04,9,01,07,05,11,03,14,10,00,06,13}
    };
    decimal = S_Box_1[row][column];
    return DecimalToBinary(decimal, 4);
}
deque<int> S_Box_2(int row, int column)
{
    int decimal = 0;
    int S_Box_2[4][16] =
    {
        {15,01,8,14,06,11,03,04,9,07,02,13,12,00,05,10}
        , {03,13,04,07,15,02,8,14,12,00,01,10,06,9,11,05}
        , {00,14,07,11,10,04,13,01,05,8,12,06,9,03,02,15}
        , {13,8,10,01,03,15,04,02,11,06,07,12,00,05,14,9}
    };
    decimal = S_Box_2[row][column];
    return DecimalToBinary(decimal, 4);
}
deque<int> S_Box_3(int row, int column)
{
    int decimal = 0;
    int S_Box_3[4][16] =
    {
        {10,00,9,14,06,03,15,05,01,13,12,07,11,04,02,8}
        , {13,07,00,9,03,04,06,10,02,8,05,14,12,11,15,01}
        , {13,06,04,9,8,15,03,00,11,01,02,12,05,10,14,07}
        , {01,10,13,00,06,9,8,07,04,15,14,03,11,05,02,12}
    };
    decimal = S_Box_3[row][column];
    return DecimalToBinary(decimal, 4);
}
deque<int> S_Box_4(int row, int column)
{
    int decimal = 0;
    int S_Box_4[4][16] =
    {
        {07,13,14,03,00,06,9,10,01,02,8,05,11,12,04,15}
        , {13,8,11,05,06,15,00,03,04,07,02,12,01,10,14,9}
        , {10,06,9,00,12,11,07,13,15,01,03,14,05,02,8,04}
        , {03,15,00,06,10,01,13,8,9,04,05,11,12,07,02,14}
    };
    decimal = S_Box_4[row][column];
    return DecimalToBinary(decimal, 4);
}
deque<int> S_Box_5(int row, int column)
{
    int decimal = 0;
    int S_Box_5[4][16] =
    {
        {02,12,04,01,07,10,11,06,8,05,03,15,13,00,14,9}
        , {14,11,02,12,04,07,13,01,05,00,15,10,03,9,8,06}
        , {04,02,01,11,10,13,07,8,15,9,12,05,06,03,00,14}
        , {11,8,12,07,01,14,02,13,06,15,00,9,10,04,05,03}
    };
    decimal = S_Box_5[row][column];
    return DecimalToBinary(decimal, 4);
}
deque<int> S_Box_6(int row, int column)
{
    int decimal = 0;
    int S_Box_6[4][16] =
    {
        {12,01,10,15,9,02,06,8,00,13,03,04,14,07,05,11}
        , {10,15,04,02,07,12,9,05,06,01,13,14,00,11,03,8}
        , {9,14,15,05,02,8,12,03,07,00,04,10,01,13,11,06}
        , {04,03,02,12,9,05,15,10,11,14,01,07,06,00,8,13}
    };
    decimal = S_Box_6[row][column];
    return DecimalToBinary(decimal, 4);
}
deque<int> S_Box_7(int row, int column)
{
    int decimal = 0;
    int S_Box_7[4][16] =
    {
        {04,11,02,14,15,00,8,13,03,12,9,07,05,10,06,01}
        , {13,00,11,07,04,9,01,10,14,03,05,12,02,15,8,06}
        , {01,04,11,13,12,03,07,14,10,15,06,8,00,05,9,02}
        , {06,11,13,8,01,04,10,07,9,05,00,15,14,02,03,12}
    };
    decimal = S_Box_7[row][column];
    return DecimalToBinary(decimal, 4);
}
deque<int> S_Box_8(int row, int column)
{
    int decimal = 0;
    int S_Box_8[4][16] =
    {
        {13,02,8,04,06,15,11,01,10,9,03,14,05,00,12,07}
        , {01,15,13,8,10,03,07,04,12,05,06,11,00,14,9,02}
        , {07,11,04,01,9,12,14,02,00,06,10,13,15,03,05,8}
        , {02,01,14,07,04,10,8,13,15,12,9,00,03,05,06,11}
    };
    decimal = S_Box_8[row][column];
    return DecimalToBinary(decimal, 4);
}
//-------------------------------------------------------------------------------
deque<int> S_Boxes(deque<int> input_48bits)
{
    int counter = 1;
    deque<int>output_32bits;
    deque<int>S1;
    deque<int>S2;
    deque<int>S3;
    deque<int>S4;
    deque<int>S5;
    deque<int>S6;
    deque<int>S7;
    deque<int>S8;
    for(int i = 0 ; i <input_48bits.size() ; i+=6)
    {
        deque<int>row_6bits;
        for(int j = i ; j < i+6 ; j++)
        {
            row_6bits.push_back(input_48bits[j]);
        }
        deque<int>row_first_last_bit(2);
        deque<int>row_4_middle_bits(4);

        row_first_last_bit = {row_6bits[0], row_6bits[5]};
        row_4_middle_bits = {row_6bits[1],row_6bits[2],row_6bits[3],row_6bits[4] };

        int row = BinaryToDecimal(row_first_last_bit);
//        cout<<"row:"<<row<<endl;
        int column = BinaryToDecimal(row_4_middle_bits);
//        cout<<"column:"<<column<<endl;
        if(counter == 1)
        {
            S1 = S_Box_1(row, column);
        }
        else if(counter == 2)
        {
            S2 = S_Box_2(row, column);
        }
        else if(counter == 3)
        {
            S3 = S_Box_3(row, column);
        }
        else if(counter == 4)
        {
            S4 = S_Box_4(row, column);
        }
        else if(counter == 5)
        {
            S5 = S_Box_5(row, column);
        }
        else if(counter == 6)
        {
            S6 = S_Box_6(row, column);
        }
        else if(counter == 7)
        {
            S7 = S_Box_7(row, column);
        }
        else if(counter == 8)
        {
            S8 = S_Box_8(row, column);
        }
        counter++;
    }
    for(int i = 1 ; i <= 8 ; i++)
    {
        if( i == 1)
        {
            output_32bits.insert(output_32bits.begin(),S1.begin(), S1.end());
        }
        else if( i == 2)
        {
            output_32bits.insert(output_32bits.end(), S2.begin(), S2.end());
        }
        else if( i == 3)
        {
            output_32bits.insert(output_32bits.end(), S3.begin(), S3.end());
        }
        else if( i == 4)
        {
            output_32bits.insert(output_32bits.end(), S4.begin(), S4.end());
        }
        else if( i == 5)
        {
            output_32bits.insert(output_32bits.end(), S5.begin(), S5.end());
        }
        else if( i == 6)
        {
            output_32bits.insert(output_32bits.end(), S6.begin(), S6.end());
        }
        else if( i == 7)
        {
            output_32bits.insert(output_32bits.end(), S7.begin(), S7.end());
        }
        else if( i == 8)
        {
            output_32bits.insert(output_32bits.end(), S8.begin(), S8.end());
        }
    }
    return output_32bits;
}
//-------------------------------------------------------------------------------
deque<int> Permutation(deque<int> R)///Permutation
{
    deque<int> P_F_function_table =
    {
        16,7,20,21,29,12,28,17
        ,1,15,23,26,5,18,31,10
        ,2,8,24,14,32,27,3,9
        ,19,13,30,6,22,11,4,25
    };
    return diffusion(P_F_function_table, R);
}
//-------------------------------------------------------------------------------
deque<int> F_function (deque<int> R,deque<int> ki)///F-Function
{
    ///Expansion
    deque<int> R_new1(48);
    R_new1=Expansion(R);
    cout<<"Expansion:";
    for(auto it=R_new1.begin(); it!=R_new1.end(); it++)
    {
        cout << *it;
    }
    cout<<endl;
    ///XOR
    deque<int> R_new2(48);
    R_new2 = XOR_key(R_new1, ki);
    for(int i=0; i<48; i++ )
    {
        R_new2[i]=XOR(R_new1[i],ki[i]);
    }
    cout<<"XOR_key in F_function:";
    for(auto it=R_new2.begin(); it!=R_new2.end(); it++)
    {
        cout << *it;
    }
    cout<<endl;
    ///S_Boxes
    deque<int> R_new3(32);
    R_new3 = S_Boxes(R_new2);
    cout<<"S_Boxes:";
    for(auto it=R_new3.begin(); it!=R_new3.end(); it++)
    {
        cout << *it;
    }
    cout<<endl;
    ///P_F_function
    R_new3=Permutation(R_new3);
    cout<<" Permutation in F_function:";
    for(auto it=R_new3.begin(); it!=R_new3.end(); it++)
    {
        cout << *it;
    }
    cout<<endl;
    return R_new3;
}
//-------------------------------------------------------------------------------
deque<int> PC_1 (deque<int> k) ///PC-Tables
{
    deque<int> PC1_table =
    {
        57,49,41,33,25,17,9,1
        ,58,50,42,34,26,18,10,2
        ,59,51,43,35,27,19,11,3
        ,60,52,44,36,63,55,47,39
        ,31,23,15,7,62,54,46,38
        ,30,22,14,6,61,53,45,37
        ,29,21,13,5,28,20,12,4
    };
    return diffusion(PC1_table, k);
}
deque<int> PC_2 (deque<int> k)
{
    deque<int> PC2_table =
    {
        14,17,11,24,1,5,3,28
        ,15,6,21,10,23,19,12,4
        ,26,8,16,7,27,20,13,2
        ,41,52,31,37,47,55,30,40
        ,51,45,33,48,44,49,39,56
        ,34,53,46,42,50,36,29,32
    };
    return diffusion(PC2_table, k);
}
//-------------------------------------------------------------------------------
deque<int> shifting_left(deque<int>dq, int transform_no)
{
    if(transform_no == 1 || transform_no == 2 || transform_no == 9 || transform_no == 16)
    {
        dq.push_back(dq.front());
        dq.pop_front();
    }
    else
    {
        dq.push_back(dq.front());
        dq.pop_front();
        dq.push_back(dq.front());
        dq.pop_front();
    }
    return dq;
}
//-------------------------------------------------------------------------------
deque<int> shifting_right(deque<int>dq, int transform_no)
{
    if(transform_no == 2 || transform_no == 9 || transform_no == 16)
    {
        dq.push_front(dq.back());
        dq.pop_back();
    }
    else if(transform_no == 1)
    {
        return dq;
    }
    else
    {
        dq.push_front(dq.back());
        dq.pop_back();
        dq.push_front(dq.back());
        dq.pop_back();
    }
    return dq;
}
//-------------------------------------------------------------------------------

deque<int> Transform_Encryption(deque<int> C, deque<int> D, int transform_no)
{
    deque<int> subkey;
    C = shifting_left(C, transform_no);
    cout<<"  C shifting_left:";
    for(auto it=C.begin(); it!=C.end(); it++)
    {
        cout << *it;
    }
    cout<<endl;
    D = shifting_left(D, transform_no);
    cout<<" D shifting_left:";
    for(auto it=D.begin(); it!=D.end(); it++)
    {
        cout << *it;
    }
    cout<<endl;
    subkey.insert(subkey.begin(),C.begin(), C.end());
    subkey.insert(subkey.end(),D.begin(), D.end());
    cout<<"shifting_left:";
    for(auto it=subkey.begin(); it!=subkey.end(); it++)
    {
        cout << *it;
    }
    cout<<endl;
    subkey = PC_2(subkey);
    cout<<"PC_2 inTransform_Encryption:";
    for(auto it=subkey.begin(); it!=subkey.end(); it++)
    {
        cout << *it;
    }
    cout<<endl;
    return subkey;
}
deque<int> Transform_Decryption(deque<int> C, deque<int> D, int transform_no)
{
    deque<int>subkey;
    C = shifting_right(C, transform_no);
    D = shifting_right(D, transform_no);
    subkey.insert(subkey.begin(),C.begin(), C.end());
    subkey.insert(subkey.end(),D.begin(), D.end());
    subkey = PC_2(subkey);
    return subkey;
}
//-------------------------------------------------------------------------------
deque<int> CF;
deque<int> DF;
deque<int> DES(deque<int> plainText, deque<int> key)
{
    deque<int> C;
    deque<int> D;
    deque<int>IP_output = IP(plainText);
    cout<<"IP_output:";
    for(auto it=IP_output.begin(); it!=IP_output.end(); it++)
    {
        cout << *it;
    }
    cout<<endl;
    deque<int>Right;
    deque<int>Left;
    deque<int>new_Right;
    deque<int>new_Left;
    deque<int>key_56bits;
    deque<int> key1(56);


    for(int i = 0 ; i < 32 ; i++)//Dividing the IP output int Left and Right
    {
        new_Left.push_back(IP_output[i]);
        new_Right.push_back(IP_output[i+32]);
    }
    //==============
    key_56bits = PC_1(key); //passing the key by PC-1
    cout<<"PC_1 in DES:";
    for(auto it=key_56bits.begin(); it!=key_56bits.end(); it++)
    {
        cout << *it;
    }
    cout<<endl;
    for(int i = 0 ; i < 28 ; i++)//Dividing the output into C and D
    {
        C.push_back(key_56bits[i]);
        D.push_back(key_56bits[i+28]);
    }
    cout<<"C in DES:";
    for(auto it=C.begin(); it!=C.end(); it++)
    {
        cout << *it;
    }
    cout<<"D in DES:";
    for(auto it=D.begin(); it!=D.end(); it++)
    {
        cout << *it;
    }
    cout<<endl;
    //==============
    cout<<"------------------------------------------------------------------"<<endl;
    for(int round = 1 ; round <= 16 ; round++)//Starting Rounds
    {
        Right = new_Right;
        Left = new_Left;
        new_Right = XOR_key(Left, F_function(new_Right, Transform_Encryption(C, D, round)));
        C = shifting_left(C, round);
        D = shifting_left(D, round);
        new_Left = Right;

        if(round==16)
        {
            CF=C;
            DF=D;
        }
        cout<<"new_Right"<<round<<":";
        for(auto it=new_Right.begin(); it!=new_Right.end(); it++)
        {
            cout << *it;
        }
        cout<<endl<<"new_Left"<<round<<":";
        for(auto it=new_Left.begin(); it!=new_Left.end(); it++)
        {
            cout << *it;
        }
        cout<<endl;
        cout<<"------------------------------------------------------------------ round no "<<round <<" :"<<endl;
    }
    //==============
    deque<int>IP_inverse_input;

    IP_inverse_input.insert(IP_inverse_input.begin(),new_Right.begin(), new_Right.end());
    IP_inverse_input.insert(IP_inverse_input.end(),new_Left.begin(), new_Left.end());
    cout<<"IP_inverse_input"<<endl;
    for(auto it=IP_inverse_input.begin(); it!=IP_inverse_input.end(); it++)
    {
        cout << *it;
    }
    cout<<endl;
    deque<int>CipherText = IP_inverse(IP_inverse_input);
    return CipherText;
}
//-------------------------------------------------------------------------------
deque<int> Decryption(deque<int> CipherText, deque<int> key)///Decryption
{
    deque<int> C;
    deque<int> D;
    deque<int>IP_output = IP(CipherText);
    deque<int>Right;
    deque<int>Left;
    deque<int>new_Right;
    deque<int>new_Left;
    deque<int>key_56bits;

    for(int i = 0 ; i < 32 ; i++)//Dividing the IP output int Left and Right
    {
        new_Left.push_back(IP_output[i]);
        new_Right.push_back(IP_output[i+32]);
    }
    //==============
    //key_56bits = PC_1(key); //passing the key by PC-1
    //key_56bits = PC_2(key_56bits);
//    for(int i = 0 ; i < 28 ; i++)//Dividing the output into C and D
//    {
////        C.push_back(key_56bits[i]);
////        D.push_back(key_56bits[i+28]);
//    }
    C = CF;
    D = DF;
    key_56bits.insert(key_56bits.begin(),C.begin(), C.end());
    key_56bits.insert(key_56bits.end(),D.begin(), D.end());
    key_56bits = PC_2(key_56bits);
    Right = new_Right;
    Left = new_Left;
    new_Right = XOR_key(Left, F_function(new_Right, Transform_Decryption(C, D, 1)));
    C = shifting_right(C, 1);
    D = shifting_right(D, 1);
    new_Left = Right;
    //==============
    for(int round = 2 ; round <= 16 ; round++)//Starting Rounds
    {
                cout<<"------------------------------------------------------------------ round no "<<round <<" :"<<endl;
        Right = new_Right;
        Left = new_Left;
        new_Right = XOR_key(Left, F_function(new_Right, Transform_Decryption(C, D, round)));
        C = shifting_right(C, round);
        D = shifting_right(D, round);
        new_Left = Right;
                cout<<"------------------------------------------------------------------"<<endl;

    }
    //==============
    deque<int>IP_inverse_input;
    IP_inverse_input.insert(IP_inverse_input.begin(),new_Right.begin(), new_Right.end());
    IP_inverse_input.insert(IP_inverse_input.end(),new_Left.begin(), new_Left.end());
    deque<int> plainText= IP_inverse(IP_inverse_input);
    return plainText ;
}
//-------------------------------------------------------------------------------
int main()
{
    //======================
    ///Entering and handling the input
    string Plain_text,key;
    string Encrypted_text="";
    string cipher_text;
    cout<<"Enter the Plain Text Please:";
    getline(cin,Plain_text);
    while(Plain_text.length()%8 != 0)
    {
        Plain_text+='*';
    }
    cout<<"Enter the Key Please:";
    getline(cin,key);
    cout<<endl;
    while(key.length()!=8)
    {
        cout<<"Please enter another Key :";
        getline(cin,key);
        cout<<endl;
    }
    //======================
    ///Testing
    cout<<"Plain_text:"<<Plain_text<<" size:"<<Plain_text.length()<<endl;
    cout<<"Key:"<<key<<endl;
    //======================
    ///Converting Key to binary
    deque<int> key_binary(64);
    key_binary= text_toBinary(key);
    //======================
    int count=0;
    int block_no=1;
    string plain8="";
    string FD="";
    deque<int> cipher_binary(64);
    while(count!=Plain_text.length()+1)
    {
        if((plain8.length()) % 8==0 && count!=0)
        {
            deque<int> plain_binary(64);
            plain_binary= text_toBinary(plain8);
            /////////////////////////////////////////special for other 8s
            plain8="";
            plain8+=Plain_text[count];
            /////////////////////////////////////////
            cout<<"plain_binary for block "<<block_no<<":";
            for(auto it=plain_binary.begin(); it!=plain_binary.end(); it++)
            {
                cout << *it;
            }
            cout<<endl;
            cout<<"plain_binary size for block "<<block_no<<":"<<plain_binary.size();
            cout<<endl;
            cout<<"decrypt of plain_binary for block "<<block_no<<":"<<endl;
            Encrypted_text+=BinarytoASCII(plain_binary);
            cout<<Encrypted_text<<endl;
            //======================
            ///DES Encryption Start
            cout<<"Begin of DES for block "<<block_no<<endl;
            cipher_binary=DES(plain_binary,key_binary);
            for(auto it=cipher_binary.begin(); it!=cipher_binary.end(); it++)
            {
                cout << *it;
            }
            cout<<endl;
            cout<<"cipher_binary after DES size for block "<<block_no<<":"<<cipher_binary.size();
            cout<<endl;
            Encrypted_text="";
            cout<<"Encrypted text after DES for block "<<block_no<<":";
            Encrypted_text+=BinarytoASCII(cipher_binary);
            cout<<Encrypted_text<<endl;
            ///DES Encryption End
            //======================
            cout<<endl;
            cout<<"=========Decryption for block "<<block_no<<"========="<<endl;
            deque<int>final_round_key;///Decryption
            deque<int>Decrypted_text;
            string decrypted_string = "";
            final_round_key.insert(final_round_key.begin(),CF.begin(), CF.end());
            final_round_key.insert(final_round_key.end(),DF.begin(), DF.end());
            Decrypted_text = Decryption(cipher_binary, final_round_key);
            //======================
            cout<<"Decrypted text Binary for block "<<block_no<<":";///Printing Decrypted Binary text
            //Decrypted_text=plain_binary;
            for(auto it=Decrypted_text.begin(); it!=Decrypted_text.end(); it++)
            {
                cout << *it;
            }
            //======================
            decrypted_string+=BinarytoASCII(Decrypted_text);///Printing Decrypted String text
            cout<<endl<<"Decrypted String text for block "<<block_no<<":"<<decrypted_string<<endl;
            FD+=decrypted_string;
            block_no++;
        }
        else
        {
            plain8+=Plain_text[count];
        }
        count++;

    }
    cout<<"Full decrypted string :"<<FD<<endl;
    //======================

    return 0;
}
