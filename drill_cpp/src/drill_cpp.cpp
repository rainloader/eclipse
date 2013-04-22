#include <process.h>
#include <windows.h>
#include <stdio.h>

class AAA
{
public:

 AAA(const char *str)
 {
  int a = strlen(str);
  memcpy(&m_str,str,strlen(str)+1);
 }

 ~AAA()
 {}

 static UINT WINAPI hello(LPVOID p)
 {
  AAA *aaa = (AAA*)p;
  aaa->print();

  return 0;
 }

 void start(void)
 {
  _beginthreadex(NULL,0, hello, (LPVOID)this,0,NULL);
 }


private:
 char m_str[10];

 void print(void)
 {
  printf("%s\n",m_str);
 }

};


int main()
{
 AAA aaa("hello");
 aaa.start();
 Sleep(5000);
}

