#pragma once
class ProgressDelegate
{
public:

	//������������ɺ󴥷���֪ͨ�¼�
	virtual void loadingFinished() = 0;

	//�����趨���ٶȸı��������ʱ�䵽���֪ͨʹ����
	virtual void progressPercentageSetter(float percentage)=0;
};
