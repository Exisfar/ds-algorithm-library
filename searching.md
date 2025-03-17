# Searching

## Binary Search

- [【二分查找为什么总是写错？】](https://www.bilibili.com/video/BV1d54y1q7k7/?share_source=copy_web&vd_source=1bf79132ed79a1a3701cb6da3a16e857)


这个视频并没有讲解【没有蓝色区域】和【没有红色区域】的细节如何处理， 比如视频中查找第一个大于等于5的元素，如果数组中所有元素都小于5那么，返回的r 直接访问会越界，需要特殊处理一下， 同理 返回 L 的时候如果是-1，也需要特殊处理才行


```py
l = -1, r = N
while l + 1 != r:
  m = (l + r) / 2
  if isBlue(m): # l最终指向蓝色区域边界
    l = m
  else
    r = m
return l or r 
```
