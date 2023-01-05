import sys

input = sys.stdin.readline
def eprint(*args, **kwargs): print(*args, file=sys.stderr, **kwargs)
def strs(): return input().split()
def ints(): return map(int, input().split())

s = ''' @@@   @@@ 
@   @ @   @
@    @    @
@         @
 @       @ 
  @     @  
   @   @   
    @ @    
     @     
'''
N, = ints()
print(s * N)