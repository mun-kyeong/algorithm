def solution(sizes):
    maxW = 0
    maxH = 0
    for [w, h] in sizes:
        if(w > h) :
            maxW = max(maxW, w)
            maxH = max(maxH, h)
        else :
            maxW = max(maxW, h)
            maxH = max(maxH, w)
    return maxW * maxH