import os

filePath = './APP'

for i,j,p in os.walk(filePath):
	#print(i,j,k)
	for k in p:
		filename = os.path.splitext(k)[0]
		filetial = os.path.splitext(k)[1][1:]
		if filetial == 'c':	#函数文件需要处理
			if filename.find('_Cal_Data') == -1 :	#不是*_Cal_Data.c文件
				if filename != 'DHP_Sub_HardwireSignal_Filter' and filename != 'DHP_model' and filename != 'DHP':
					if filename != 'Funcs_DHP_lib' and filename != 'DHP_CC_FltStore':#不为指定保留文件
						print(k)
						os.remove('./APP/'+k)#依据路径删除文件
print('end')
input()