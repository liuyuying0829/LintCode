/*
208 ��ֵ���������

ʵ�ָ�ֵ��������غ�����ȷ����

�µ����ݿ�׼ȷ�ر�����
�ɵ����ݿ�׼ȷ��ɾ��/�ͷ�
�ɽ��� A = B = C ��ֵ

˵��
����ֻ������C++����Ϊ Java �� Python û�жԸ�ֵ����������ػ��ơ�

����
������� A = B ��ֵ���� A �е����ݱ�ɾ����ȡ����֮���� B �е����ݡ�

������� A = B = C ��ֵ���� A �� B �������� C �е����ݡ�
*/
class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        // write your code here
        
        if(this!=&object)  
        {  
            delete this->m_pData;  
            if(object.m_pData != nullptr)  
            {  
                this->m_pData = new char[strlen(object.m_pData)+1];  
                strcpy(this->m_pData,object.m_pData);  
            }  
        }  
        return *this;  
    }
};