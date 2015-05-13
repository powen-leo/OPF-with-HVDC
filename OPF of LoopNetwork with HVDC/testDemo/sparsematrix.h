#include <stdio.h>
#include <math.h>
#include <stdlib.h>		//�ṩmalloc()ԭ�ͺ���
#include <malloc.h>
#include <stdbool.h>

typedef struct Element
{
	double VA;			//ϡ������з�0Ԫ��aij
	int IA;				//Ԫ��aij������
	int JA;				//Ԫ��aij������
	struct Elem * NEXT;	//��һ��Ԫ�صĵ�ַ�����һ��Ԫ�ص���һ��Ԫ�ص�ַΪNULL
}Elem;

typedef struct SparseMatix
{
	struct Elem * HEAD;	//ϡ������һ��Ԫ�ص�ַ
	int Ni;			//ϡ���������
	int Nj;			//ϡ���������
	int NElement;	//��0Ԫ�ظ���
}SparseMat;

typedef SparseMat * Mat; //Mat����ָ��һ��ϡ���������

/*������  ��������ʼ��ϡ�����
 *����ǰ��PMatϡ�����ָ��
 *�����󣺸��б���ʼ��Ϊ0ֵ
 */
void InitMat (Mat * pMat);

/*������	  ��������ʼ����Ԫ��
 *����ǰ��pElemΪ��Ԫ��ָ��
 *�����󣺸�Ԫ�ؼ������Ϣ��ʼ��Ϊ0ֵ
 */
void InitElem (Elem * pElem);

/*������  ȷ���б��Ƿ�Ϊ��
 *����ǰ��PMatָ��һ���Ѿ���ʼ���ľ���
 *�������������Ϊ�շ���ture�����򷵻�false
 */
bool MatIsEmpty (const Mat * pMat);

/*������  Ϊ��������Ԫ�ط����ڴ棬�����丳ֵ
 *����ǰ������double���͵�Ԫ�أ�pMatָ���Ѿ���ʼ�����ָ��
 *�����󣺰���Ԫ�����ӵ�������ĩβ
 */
bool addElement (double aij, int i, int j, Mat * pMat);

/*������  ������������Ԫ��
 *����ǰ��������Ԫ�ص�ֵ���С��кţ�������ɶ���Ԫ��ָ��ĳ�ʼ��
 *�����󣺰Ѷ���Ԫ�ؽ��и�ֵ��ͬʱ�������к����кţ������������
 */
bool addList (double aij, int i, int j, Mat * pMat, Elem * pNew);

/*������  �Ƴ������е�Ԫ��Aij
 *����ǰ��pMat���Ѿ���ʼ���ľ���
 *�������ھ������Ƴ�Ԫ��Aij
 */
bool removeElement (Mat * pMat, int i, int j);

/*������  ��ӡϡ�����
 *����ǰ��pMatΪ��ʼ��������Ԫ�صľ���
 *���������׼����д�ӡϡ�����
 */
void showMat (Mat * pMat);