import math

def solution(progresses, speeds):
    answer = []
    remains = []
    for idx,i in enumerate(progresses):
        remains.append(math.ceil((100-i)/speeds[idx]))
#      remains = [7,3,9]
    anchor = 0
    for idx,i in enumerate(remains):
        print(remains[idx], anchor)
        if(idx>=1 and anchor >= remains[idx]):
            answer[len(answer)-1] += 1
            continue
        answer.append(1)
        anchor = i
        
    return answer