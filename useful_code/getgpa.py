# -*- coding:utf-8 -*-

## read score
fin = open('score3.txt','r', encoding='UTF-8')
arr_id = []
arr_name = []
arr_credit = []
arr_credit_sum = []
arr_sum = []
arr_gpa = []
arr_class = []
last_id = '﻿2015011375'
index = -1
credit_sum = 0
line = fin.readline()
while line:
    line = line.strip()
    line.replace('\n','')
    words = line.split('\t')
    line = fin.readline()
    print(words)
    if len(words) != 7:
        print('error: ' + line + ' ' + str(len(words)))
        break
    tid = words[0]
    print(tid)
    name = words[1]
    tclass = words[6]
    if tid != last_id:
        if index > -1:
            arr_gpa.append(float(arr_sum[index])/float(arr_credit[index]))
            arr_credit_sum.append(credit_sum)
            credit_sum = 0
        index += 1
        arr_id.append(tid)
        arr_name.append(name)
        arr_class.append(tclass)
        arr_credit.append(0)
        arr_sum.append(0)
        last_id = words[0]
    if (words[4] != 'N/A')or (words[4] == 'N/A' and words[3] != 'W'and words[3] != 'I'):
        credit_sum += int(words[5])
    if words[4] == 'N/A':
        continue
    course = words[2]
    score = float(words[4])
    credit = int(words[5])
    arr_sum[index] += score * float(credit)
    arr_credit[index] += credit

# print index
print(index)
arr_gpa.append(float(arr_sum[index])/float(arr_credit[index]))
arr_credit_sum.append(credit_sum)
fin.close()

## write gpa
fout = open('result3.txt', 'w')
fout.write('学号\t姓名\t班级\t总学分\t绩点学分\t总绩点\tGPA\n')
print(arr_name)
for i in range(153):
    fout.write(arr_id[i] + '\t' + arr_name[i] + '\t' + str(arr_class[i]) + '\t' + str(arr_credit_sum[i]) + '\t' + str(arr_credit[i]) + '\t' + str(arr_sum[i]) + '\t' + str(arr_gpa[i]) + '\n')
fout.close()


# 2015011000	xxx	体育(1)	A	4	1	计xx
