#include<iostream>
#include<vector>
#include<algorithm>//���������̶�� �Լ��� ����
#include<ctime>//time�Լ�������ϱ����ؼ�
using namespace std;



vector<int> getRandomVector(int n)//��ȣ�� ���ø� ��ȣ�ȿ� ��Ʈ�� �־��ָ� ��Ʈ�θ���
{
   vector<int> vec;
   for (int i = 0; i < n; i++)vec.push_back(i);
   srand((unsigned int)time(0));//�̰� �Ⱦ��� ���������� �Ȱ��� ����� �����ִ�.
   random_shuffle(vec.begin(), vec.end());//������ ó���ּҿ� ������ ������ �ּҸ� �ָ� ���´�.
   return vec;
}

void printVector(const vector<int>& vec)//�׳��ϸ� ���縦�ϴ� ������ �ϵ��� &�� ���̰� ���� �ǵ帮�� ������ const�� ���δ�.
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
         // j > 0 && sorted[j]> sorted[j-1] �� ���� �տ� �;��ϴ� ������ j�� 0�̵Ǹ� ��Ƽ�� -1 �������ϰԵǼ� ����
         //j�� ������ �ǵڰ�  �ǵڿ� �״����ǵڸ� ���ؼ� �ǵڰ� ������ ����
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
   ���� �ۼ��߶� �κ�
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

int partition2(int* arr, int len)//�޸𸮸� �������� �ʴ� ���
{
   int temp,p = 0;//�ǹ����� ���� ������ ������ ����
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


int partitionBack(int* arr, int len)//�ں��͹���
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

void quickSort(int* arr, int len)//�������� �ּҿ� �������� ����
{
   if (len <= 1) return;
   int p;
   p = partition(arr, len); //�Ǻ��ڸ� ����
   quickSort(arr, p);
   quickSort(arr + p + 1, len - p - 1);
}

int main()
{
   vector<int> vec = getRandomVector(100);//���̰� 100�̰� �׻����� ���� �����ϰ� ä���� ���͸� ���� ����
   printVector(vec);

   vector<int> sorted = insertionSort(vec);
   printVector(sorted);
   
   quickSort(vec.data(), vec.size());
   system("pause");
   return 0;
}