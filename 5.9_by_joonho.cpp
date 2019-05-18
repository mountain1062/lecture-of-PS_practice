#include<iostream>
#include<vector>
#include<algorithm>//랜덤셔플이라는 함수가 있음
#include<ctime>//time함수를사용하기위해서
using namespace std;



vector<int> getRandomVector(int n)//괄호는 템플릿 괄호안에 인트를 넣어주면 인트로만듬
{
   vector<int> vec;
   for (int i = 0; i < n; i++)vec.push_back(i);
   srand((unsigned int)time(0));//이걸 안쓰면 돌릴때마다 똑같은 결과가 섞여있다.
   random_shuffle(vec.begin(), vec.end());//벡터의 처음주소와 벡터의 마지막 주소를 주면 섞는다.
   return vec;
}

void printVector(const vector<int>& vec)//그냥하면 복사를하니 참조만 하도록 &를 붙이고 값을 건드리지 않으니 const를 붙인다.
{
   for (int i = 0; i < vec.size(); i++)
   {
      cout << vec[i] << " ";
   }
   cout << endl;
}

vector<int> insertionSort(const vector<int>& vec)
{
   vector<int> sorted;
   int temp;
   for (int i = 0; i < vec.size(); i++)
   {
      sorted.push_back(vec[i]);//2 5 1
      for (int j = sorted.size()-1; j > 0 && sorted[j] < sorted[j-1]; j--)
         // j > 0 && sorted[j]> sorted[j-1] 중 저게 앞에 와야하는 이유는 j가 0이되면 소티드 -1 에접근하게되서 에러
         //j는 벡터의 맨뒤값  맨뒤와 그다음맨뒤를 비교해서 맨뒤가 작으면 스왑
      {
         temp = sorted[j];
         sorted[j] = sorted[j - 1];
         sorted[j - 1] = temp;
      }
   }
   return sorted;
}

int partition(int* arr, int len)
{
   int* arr2 = new int[len];
   int lenLeft = 0, lenRight = 0;
   for (int i = 1; i < len; i++)
   {
      if (arr[i] < arr[0])
      {
         arr2[lenLeft] = arr[i];
         lenLeft++;
      }
      else
      {
         arr2[len - lenRight - 1] = arr[i];
         lenRight++;
      }
   }
   arr2[lenLeft] = arr[0];
   
   for (int i = 0; i < len; i++)
   {
      arr[i] = arr2[i];
   }
   delete[] arr2;
   return lenLeft;
   /*
   내가 작성했떤 부분
   int p = arr[0];
   int c = 0;
   for (int i = 0; i < len; i++)
   {
      if (arr[i] < p)
      {
         arr2[c] = arr[i];
         c++;
      }
   }
   arr2[c] = p;
   c++;
   for (int i = 0; i < len; i++)
   {
      if (arr[i] > p)
      {
         arr2[c] = arr[i];
         c++;
      }
   }
   */
}

int partition2(int* arr, int len)//메모리를 낭비하지 않는 방법
{
   int temp,p = 0;//피벗보다 작은 원소의 갯수를 유지
   for (int i = 1; i < len; i++)
   {
      if (arr[i] < arr[0])
      {
         p++;
         temp = arr[i]; arr[i] = arr[p]; arr[p] = temp;
      }
   }
   temp = arr[0]; arr[0] = arr[p]; arr[p] = temp;
   return p;
}


int partitionBack(int* arr, int len)//뒤부터버전
{
   int* arr2 = new int[len];
   int lenLeft = 0, lenRight = 0;
   for (int i = 0; i < len -1; i++)//
   {
      if (arr[i] < arr[len-1])
      {
         arr2[lenLeft] = arr[i];
         lenLeft++;
      }
      else
      {
         arr2[len - lenRight - 1] = arr[i];
         lenRight++;
      }
   }
   arr2[lenLeft] = arr[0];

   for (int i = 0; i < len; i++)
   {
      arr[i] = arr2[i];
   }
   delete[] arr2;
   return lenLeft;
   
}

void quickSort(int* arr, int len)//데이터의 주소와 데이터의 개수
{
   if (len <= 1) return;
   int p;
   p = partition(arr, len); //피봇자리 리턴
   quickSort(arr, p);
   quickSort(arr + p + 1, len - p - 1);
}

int main()
{
   vector<int> vec = getRandomVector(100);//길이가 100이고 그사이의 수로 랜덤하게 채워진 벡터를 만들어서 리턴
   printVector(vec);

   vector<int> sorted = insertionSort(vec);
   printVector(sorted);
   
   quickSort(vec.data(), vec.size());
   system("pause");
   return 0;
}