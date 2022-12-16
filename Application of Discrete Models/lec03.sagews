︠64fd1f7f-ac1a-4b34-b4c0-c5fa30a6ccb1i︠
%html
<p style="text-align: center;"><span style="font-size: large;"><strong>Application of Discrete Models Course &ndash; Lecture 3</strong></span></p>
<p style="text-align: justify;"><span style="font-size: medium;">Welcome to Application of Discrete Models. In this worksheet we will work with loops, functions, unnamed function, matrix, and vectors.</span></p>
︡dba0fbdb-b2ca-4e62-ae71-cf5d55642287︡{"done":true,"html":"<p style=\"text-align: center;\"><span style=\"font-size: large;\"><strong>Application of Discrete Models Course &ndash; Lecture 3</strong></span></p>\n<p style=\"text-align: justify;\"><span style=\"font-size: medium;\">Welcome to Application of Discrete Models. In this worksheet we will work with loops, functions, unnamed function, matrix, and vectors.</span></p>"}
︠e751b946-e768-4ad5-9d1e-5457055ec298︠

︡b7a6f708-3261-4833-8285-727d403be97d︡
︠332a3753-869b-4478-b539-8c6391bab289sio︠
︡dd5f3fe6-95c5-4dd3-9625-974675d52667︡
︠36ee2d54-4432-4aef-a4b0-2cafdfcd1954so︠
L = [1 .. 25]
L
︡137e81c8-b049-4308-8941-42d9c61a0737︡{"stdout":"[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25]\n"}︡{"done":true}
︠d16017cc-00ba-4c38-b67a-d994f0b55154so︠
n = 3
r = n*(n+1)/2
r
︡2e7882a6-7137-4c17-87b8-9cccad28d5a8︡{"stdout":"6\n"}︡{"done":true}
︠cfc700d2-4798-459e-9f3a-0e9bfe4e2947so︠
L = [i*(i+1)/2 for i in range(1,26)]
L
︡06a1b392-eb42-4c05-b507-999d2fd8f85e︡{"stdout":"[1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78, 91, 105, 120, 136, 153, 171, 190, 210, 231, 253, 276, 300, 325]\n"}︡{"done":true}
︠94af565d-9800-4084-8fee-b0edc1aded9eso︠
s = 0
L=[]
for i in range(1,26):
    s = s+i
    L.append(s)
L
︡f7563ccb-8db5-4393-8eac-13b5cc5ab5d9︡{"stdout":"[1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78, 91, 105, 120, 136, 153, 171, 190, 210, 231, 253, 276, 300, 325]\n"}︡{"done":true}
︠38113b5e-0f8c-4142-8aad-6456c2ff5b28so︠
M = matrix(4,4)
for i in range(0,4):
    for j in range(0,4):
        M[i, j] = i+j
M
︡291981ac-c746-46c9-81cf-21225ceff105︡{"stdout":"[0 1 2 3]\n[1 2 3 4]\n[2 3 4 5]\n[3 4 5 6]\n"}︡{"done":true}
︠20acd3ee-b29a-43fd-b74d-81b24b5ea5a5so︠
x = 5555
while not is_prime(x):
    x = x +1
print("The first prime number after 5555 is ", x)
︡a97a157c-ec99-40d8-9144-3546275722ef︡{"stdout":"The first prime number after 5555 is  5557\n"}︡{"done":true}
︠d964495a-52e2-41af-aa9d-235db9ab0cb4so︠
L=[1..9]
for i in L:
    if is_prime(i):
        print(i, " is prime")
︡2692d0a3-3d84-4302-859e-ff24988c7aa1︡{"stdout":"2  is prime\n3  is prime\n5  is prime\n7  is prime\n"}︡{"done":true}
︠674ccf0d-5dc8-4471-8f28-7a46817beea1so︠
L=[1..9]
for i in L:
    print("The square of ", i, "equals ", i^2)
︡ce24d672-acdb-4f48-8355-14313d4fc30d︡{"stdout":"The square of  1 equals  1\nThe square of  2 equals  4\nThe square of  3 equals  9\nThe square of  4 equals  16\nThe square of  5 equals  25\nThe square of  6 equals  36\nThe square of  7 equals  49\nThe square of  8 equals  64\nThe square of  9 equals  81\n"}︡{"done":true}
︠0e43bfc4-ce0e-4275-9d01-12be9edb5570so︠
P = [is_prime(i) for i in L]
P
︡0d006a0a-1f01-4208-9210-3b230b75ebc9︡{"stdout":"[False, True, True, False, True, False, True, False, False]\n"}︡{"done":true}
︠3c6186ea-2613-48e2-a510-bfc6e85dbaf5so︠
n = 1000
prime_pi(n)
︡36096708-6b14-46aa-b849-a57a8ba92cd2︡{"stdout":"168\n"}︡{"done":true}
︠a9907a57-6541-4425-96ed-ff4fff7088a1s︠
def prime_count(n):
    counter = 0
    for i in range(0, n+1):
        if is_prime(i):
            counter += 1
    return counter
︡d250610c-c31f-4e88-8417-81cdcdd62b43︡{"done":true}
︠58c35baf-21c5-4ff0-b6c7-106c3e72bcc5so︠
prime_count(n)
︡d90cb8ba-0266-40dc-963f-ab2a3c8813c1︡{"stdout":"168\n"}︡{"done":true}
︠8d17aa5c-2200-4d10-aaa8-9738df33fed2so︠
M = matrix(5, 5, gcd)
M
︡63197476-a055-4bf0-aef0-71fb732ab41a︡{"stdout":"[0 1 2 3 4]\n[1 1 1 1 1]\n[2 1 2 1 2]\n[3 1 1 3 1]\n[4 1 2 1 4]\n"}︡{"done":true}
︠117b5e26-3dc2-48bc-9af7-b4ee5fe49812︠

︡3e07f40d-07d0-417a-a032-e3d74a348b30︡
︠337f54e8-77ba-48fc-b786-975855ae9f2aso︠
def f(i, j):
    r =gcd(i,j)
    return r
M = matrix(5, 5, f)
M
︡959c29d7-7fba-42e3-b5f8-ec4a68c74379︡{"stdout":"[0 1 2 3 4]\n[1 1 1 1 1]\n[2 1 2 1 2]\n[3 1 1 3 1]\n[4 1 2 1 4]\n"}︡{"done":true}
︠1093465f-6d29-445c-96a0-0dd41cc660ccso︠
n = 10
is_odd(n)
︡d19c6a9b-13da-4faf-87cd-20e15293a0d5︡{"stdout":"False\n"}︡{"done":true}
︠cb3b39c0-bd9a-4431-b854-b351686ffd9ao︠
if n%2 == 0:
    print(0)
︡a81f2cd5-d365-41be-919c-4de9d56822de︡
︠b170c9d2-7146-43b5-a812-9ea98b71a6fdo︠
L = [1 , 2, 3, 4]
p = 1
for i in L:
    p *= i
p
︡fd315b39-142f-4a50-9d73-cc0d528bc6bd︡{"stdout":"24\n"}︡{"done":true}
︠45b90cc7-4d8d-402e-88ac-2bb6c0dfbffeso︠
L = [1..4]
prod(L)
︡0e688ce0-ffd1-493d-b91b-770e32aee526︡{"stdout":"24\n"}︡{"done":true}
︠72597088-2ff7-4ec3-afff-e8add277bf00so︠
L=[[3,4], [5,7], [1, 8]]
s = 0
for pair in L:
    s += prod(pair)
s
︡0cce5181-8b4b-4de0-b382-d8fe04d51cdf︡{"stdout":"55\n"}︡{"done":true}
︠127eb235-500a-46e5-85a5-56323d6ef3e9so︠
reduce(lambda a, b: a+prod(b), L, 3)
︡7aab2258-6d18-431b-b255-05ad6e6b2542︡{"stdout":"58\n"}︡{"done":true}
︠d5cf1417-1b3f-483a-9609-af0656d607b4so︠
def scl_prod(L1, L2):
    return reduce(lambda a, b:a + prod(b), zip (L1, L2), 0)
scl_prod([3, 5, 1], [4, 7, 8])
︡5fd763ba-92d6-470f-90e7-01c85560419f︡{"stdout":"55\n"}︡{"done":true}
︠90107c43-ebc3-4e6a-998b-dd67a22196d2︠

︠a6620e90-b173-49f0-b9d4-57ba497ab220︠









