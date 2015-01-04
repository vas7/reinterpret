##### Some examples of usage
---
```
% reinterpret bits int 11111111111111111111111111111000
-8
```
```
% reinterpret bits uint 11111111111111111111111111111000
4294967288
```
```
% reinterpret uint int 4294967288
-8
```
```
% reinterpret int float 0
0
```
```
% reinterpret int float 1
1.4013e-45
```
```
% reinterpret int float -1
-nan
```
```
% reinterpret float bits 1
00111111100000000000000000000000
```
```
% reinterpret float bits 2
01000000000000000000000000000000
```
```
% reinterpret float bits 4
01000000100000000000000000000000
```
```
% reinterpret llong ullong -1
18446744073709551615
```
```
% reinterpret llong bits -1
1111111111111111111111111111111111111111111111111111111111111111
```
```
% reinterpret double bits nan
0111111111111000000000000000000000000000000000000000000000000000
```
```
% reinterpret double bits -nan
0111111111111000000000000000000000000000000000000000000000000000
```
```
% reinterpret bits double 0111111111111000000000000000000000000000000000000000000000000000
nan
```
---
