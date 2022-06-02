#include <bits/stdc++.h>
using namespace std;
 
// return degeleri
int priority(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
 
// infix denklemi postfix hale getiren fonksiyon
void infixCevirPostfix(string s)
{
 
    stack<char> st; 
                    
    string cikti;
 
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
 
        // eger scanledigimiz deger islenebiliyor ise cikis stringine koy
        if ((c >= 'a' && c <= 'z')|| (c >= '0' && c <= '9'))
            cikti += c;
 
        // eger scanledigimiz deger parantez baslangici '(' ise stack e pushla
        else if (c == '(')
            st.push('(');
 
        // eger scanledigimiz deger parantez sonu ')' ise pop yap ve cikis stringine (parantez basina kadar ilerle) koy
        else if (c == ')') {
            while (st.top() != '(') {
                cikti += st.top();
                st.pop();
            }
            st.pop();
        }
 
        
        else {
            while (!st.empty()&& priority(s[i]) <= priority(st.top())) {
                if (c == '^' && st.top() == '^')
                    break;
                else {
                    cikti += st.top();
                    st.pop();
                }
            }
            st.push(c);
        }
    }
 
    // stackte geriye kalanlari pop yap
    while (!st.empty()) {
        cikti += st.top();
        st.pop();
    }
 //ciktiyi yazdir
    cout << cikti;
}
 
// mainde scanfle cagiramadim bu yuzden cin ile cagiriyorum
int main()
{
    string ifade;
	printf("UYARI!lutfen kucuk karakter ve sayi girin.\n");
	printf("infix---->postfix:");
    cin>>ifade;
	infixCevirPostfix(ifade);
    return 0;
}
