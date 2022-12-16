︠de1576e4-9670-41b0-b1cd-7660f99e6b19i︠
%html
<p style="text-align: center;"><span style="font-size: large;"><strong>Application of Discrete Models Course &ndash; Lecture 2</strong></span></p>
<p style="text-align: justify;"><span style="font-size: medium;">Welcome to Application of Discrete Models. In the second worksheet you will continue learning more about some of the functions available in Sage and see what symbolic calculation means. This worksheet also introduces some useful data types: lists, sets, tuples, dictionaries, vectors and matrices.</span></p>
︡c5b389f9-337d-4aca-ab57-ddec6a6eeafb︡{"done":true,"html":"<p style=\"text-align: center;\"><span style=\"font-size: large;\"><strong>Application of Discrete Models Course &ndash; Lecture 2</strong></span></p>\n<p style=\"text-align: justify;\"><span style=\"font-size: medium;\">Welcome to Application of Discrete Models. In the second worksheet you will continue learning more about some of the functions available in Sage and see what symbolic calculation means. This worksheet also introduces some useful data types: lists, sets, tuples, dictionaries, vectors and matrices.</span></p>"}
︠40a0426c-425c-42f8-8083-6d4631b1a3fa︠

︡6821a1f6-0f84-406c-bc7f-af354f54548c︡
︠6bff6ac8-8571-4b26-907c-289dd8581c00so︠
is_prime(3)
︡3b97d680-3696-4573-89ed-067b892acabc︡{"stdout":"True"}︡{"stdout":"\n"}︡{"done":true}
︠ff4baf67-867c-420d-ad48-4136245438c7so︠
prime_pi(1111)
︡f74a2d30-f797-4ff4-951c-f8b62fd1cf5d︡{"stdout":"186\n"}︡{"done":true}
︠450e516c-94bd-4641-9645-a3b283f1c4c0so︠
factor(20)
︡ee124128-3cc5-4591-99ab-59846b9a0da8︡{"stdout":"2^2 * 5\n"}︡{"done":true}
︠ac70d6b1-72c9-4c1f-b762-5d61c15f6414so︠
factorial(10)
︡12f8b613-abc0-437c-9872-29b733a0f45c︡{"stdout":"3628800\n"}︡{"done":true}
︠1a359cbc-8589-4bb9-a7f3-c1d223a028e5so︠
factor(2112222222222222222222222222222222222222211111111111111111111111111110)
︡2bae8860-b73d-4d1a-9d22-b3ae2f6438fb︡{"stdout":"2 * 3^2 * 5 * 61 * 73333084055966083503790711 * 5246471441108274690033353742503134475549"}︡{"stdout":"\n"}︡{"done":true}
︠cd52a8b7-d6d5-41ea-b3c2-d5270df06255so︠
L = [1,2]
L
︡bfeb0c72-01dc-4db7-bfa8-b01c82e7643a︡{"stdout":"[1, 2]\n"}︡{"done":true}
︠975cc7f2-f6f5-4030-99de-ed7954144f25so︠

L = [1 ..10]
L
︡a6e49d8e-9642-49c4-b2a1-29a3bf844ce9︡{"stdout":"[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]\n"}︡{"done":true}
︠4f23af8c-46df-492c-8f42-991bf7835d16so︠
L = [i for i in range(3,11)]
L
︡92e38daf-e983-406a-9c85-109dc6fe7a15︡{"stdout":"[3, 4, 5, 6, 7, 8, 9, 10]\n"}︡{"done":true}
︠948ce071-a2bb-48c5-9025-411a5dc43c71so︠
L = [i for i in range(100) if is_prime(i)]
L
︡c6d29d97-507f-43be-8630-300215bce98d︡{"stdout":"[2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]\n"}︡{"done":true}
︠13507a5d-6156-4bbc-9a69-21e5fba979c3so︠
# Combine conditions with 'and', 'or', 'not'
L = [i for i in range(1,100) if is_prime(i) and i%5 == 1]
L
︡4a0ea63d-8ec0-4e91-a9b6-8cb811b79fd7︡{"stdout":"[11, 31, 41, 61, 71]\n"}︡{"done":true}
︠321fd3d5-350e-4743-8aad-b24179ec32easo︠
# The first ten squares
L = [i^2 for i in range(0, 10)]
L
︡8429c271-d3bd-495e-9baa-ecd9478df8b2︡{"stdout":"[0, 1, 4, 9, 16, 25, 36, 49, 64, 81]\n"}︡{"done":true}
︠43a60d9a-e164-42a9-9e79-fb43396c72ce︠

︡d549992e-8770-4366-825c-1d3ac75ce0b3︡
︠a0a8464c-2606-4342-87c9-66a3a2b82584so︠
nth_prime(31)
︡ee5b0f68-a34f-41cf-af0b-ec9fb19ba946︡{"stdout":"127\n"}︡{"done":true}
︠b42bdb23-a9c9-4d77-9a97-9d7d5d8a442aso︠
prime_pi(127)
︡5c68beb3-059d-427b-9d05-a6019b2f635e︡{"stdout":"31\n"}︡{"done":true}
︠a50605a5-f068-447e-bbc5-ec2681588557so︠
L = [nth_prime(i) for i in range(1, 101)]
sum(L)
︡0141ea7f-690e-489c-8fd4-4004be5de653︡{"stdout":"24133\n"}︡{"done":true}
︠fef55eb0-c72f-42de-a460-040dda15ea3as︠
X = Set(L)
X
︡d7b87722-e98c-40ab-9115-137015ba6e11︡{"stdout":"{0, 1, 64, 4, 36, 9, 16, 49, 81, 25}\n"}︡{"done":true}
︠5d5e7625-9c09-4bbe-99df-0ef1fb5e60d4s︠
L = [1 , 2, 3, 1, 2, 5, 8]
L
︡f217c269-6de7-4da3-9943-6d6236c99dec︡{"stdout":"[1, 2, 3, 1, 2, 5, 8]\n"}︡{"done":true}
︠9fa221a1-1485-438e-a373-1179800c3aef︠
# can not have repeated values
X = {1 , 2, 3, 1, 2, 5, 8}
X
︡db3c6a2b-21b1-499c-9564-4c99446c3d3c︡{"stdout":"{1, 2, 3, 5, 8}\n"}︡{"done":true}
︠66296e93-efd4-4914-8089-5abfa86d14bfso︠
# Sets may contain sets
S = Set([ X, 1, Set([]) ])
S
︡6f8229fd-8169-4dff-a57d-34c41c44f0d6︡{"stdout":"{{}, 1, {0, 1, 64, 4, 36, 9, 16, 49, 81, 25}}\n"}︡{"done":true}
︠c370081a-769f-4fd5-a398-b0e0d9b12f5e︠
︡71fa11ea-1316-4115-9714-a0c0483f7603︡
︠88ad7b2d-655a-431f-99fc-b92988deea30︠
︡baf933a3-6e97-474a-bc94-043134f75d69︡
︠bfc99fc9-eafd-47fc-bffa-ebf007d7f3aeo︠
Y = {1, 9, 4, 7}
Y
︡064db83c-af2a-4860-9e58-3bd7a8464c11︡{"stdout":"{1, 4, 9, 7}\n"}︡{"done":true}
︠e5cd6466-d7e3-4982-a240-0b84363e37f3so︠
X.intersection(Y)
︡94d6dad2-70bb-49b9-adfc-60cb7896900e︡{"stdout":"{1}\n"}︡{"done":true}
︠6ff8d069-b288-4738-af6a-f16ce0aae486so︠
L = [i for i in range(44,77)]
L
︡09b70760-c3b5-4e94-b8fd-42254b7978d8︡{"stdout":"[44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76]\n"}︡{"done":true}
︠60c0df5f-9d53-4fa9-8776-ec0c9144f807so︠
L[3]
︡018209ee-5a29-405f-b151-9b2472c3bb88︡{"stdout":"47\n"}︡{"done":true}
︠2f1b5c4b-dc21-4286-bab9-ec01cacd8992o︠
L[0]
︡82a4e058-92ef-4d44-9b39-e15e293f0278︡{"stdout":"44\n"}︡{"done":true}
︠2d7faaf5-3705-48ca-9cac-49d9d7833649i︠
%html
<p><span style="font-size: medium;">A dictionary is similar to a set, but to each element (now called key) belongs a value. This data structure is also called hash map in other languages.</span></p>
︡d1a8db95-1660-48f3-ac65-58da7ab2ee77︡{"done":true,"html":"<p><span style=\"font-size: medium;\">A dictionary is similar to a set, but to each element (now called key) belongs a value. This data structure is also called hash map in other languages.</span></p>"}
︠a01e0a64-28c4-4605-b4fb-0bbff89ed5beso︠
d = {1:48, "course":"app", 11:9}
d[11]
︡6b395785-8aad-452d-9360-dd69410c1326︡{"stdout":"9\n"}︡{"done":true}
︠7dbc3260-ee45-4bf1-a76c-40b54795ade0so︠
d[0]
︡d441ccfc-d4fe-45f2-a004-09b41b8233eb︡{"stderr":"Error in lines 1-1\nTraceback (most recent call last):\n  File \"/cocalc/lib/python3.9/site-packages/smc_sagews/sage_server.py\", line 1230, in execute\n    exec(\n  File \"\", line 1, in <module>\nKeyError: 0\n"}︡{"done":true}
︠ed7780e8-8a4f-4d6f-bb2d-58f8e9bdaee9so︠
0 in d
︡01c4bf99-7069-4e33-80d1-7ab7b53ed93b︡{"stdout":"False\n"}︡{"done":true}
︠f3c3e167-c91b-48d6-9718-f23a67a93e67so︠
d.keys()
︡b6c40097-1716-425c-adba-7da0d16210bb︡{"stdout":"dict_keys([1, 'course', 11])\n"}︡{"done":true}
︠213d634b-7a37-4f36-86e7-9b8a70d02d3dso︠
d.values()
︡01f68114-28ee-475b-8f35-847516ad2134︡{"stdout":"dict_values([48, 'app', 9])\n"}︡{"done":true}
︠9dd8d280-22f8-4b43-8475-8dd02b4e8c9fso︠
d = {3:5, Set([1, 2]):9, "something":"nothing"}
d[Set([1, 2])]
︡efd8159b-3219-4387-aec0-844269c4dfff︡{"stdout":"9\n"}︡{"done":true}
︠5e3c7835-6ee2-44db-813f-4136d275005eso︠
t = (1,2, 3)
t
︡975fa399-77b4-484b-a168-f545cdb481f1︡{"stdout":"(1, 2, 3)\n"}︡{"done":true}
︠3dd0d7af-7eac-41fe-a2ce-5efa5c5075e5so︠
t[0]
︡f8c9429f-621a-4011-b4db-d9f2fcaf8aeb︡{"stdout":"1\n"}︡{"done":true}
︠78a35a21-08de-495a-893e-2e14b4992ef4so︠
t[0] = 4
︡ccaf9439-e1ff-45e8-8823-5f0400dfb931︡{"stderr":"Error in lines 1-1\nTraceback (most recent call last):\n  File \"/cocalc/lib/python3.9/site-packages/smc_sagews/sage_server.py\", line 1230, in execute\n    exec(\n  File \"\", line 1, in <module>\nTypeError: 'tuple' object does not support item assignment\n"}︡{"done":true}
︠93d4bc3b-f305-408a-a10b-ebcea08bc238so︠
S = Set([1,2])
S
︡729d3518-3cc5-4105-a712-6bbc8703b547︡{"stdout":"{1, 2}\n"}︡{"done":true}
︠02516edf-31cc-475d-8bbe-ef2d1803d8e8so︠
d[S]
︡e46deddc-9cfc-440a-a207-52c3dd4b7e00︡{"stdout":"9\n"}︡{"done":true}
︠6757707c-0f46-4546-be29-1ed0d0312756so︠
# Note the order of the two uses of 'for'
[(i, j) for i in range(1, 5) for j in range(i, i+2)]
︡a14d7254-37ae-4b1a-91c1-78ef0d5a5d9d︡{"stdout":"[(1, 1), (1, 2), (2, 2), (2, 3), (3, 3), (3, 4), (4, 4), (4, 5)]"}︡{"stdout":"\n"}︡{"done":true}
︠24010e3a-999e-443e-9e07-7bc570a42e70so︠
v = vector([1, 2, 3])
M = matrix ([[4, 5, 6], [7, 8, 9], [10, 11, 12]])
M
︡ea3093b6-495d-4c2b-adcb-e58a9ca26617︡{"stdout":"[ 4  5  6]\n[ 7  8  9]\n[10 11 12]\n"}︡{"done":true}
︠839bbfa3-5dd9-44d3-a092-e9d84b6b7f6cso︠
M * v
︡0ff36bf1-cd97-49b2-8724-e072530e6b7d︡{"stdout":"(32, 50, 68)\n"}︡{"done":true}
︠79fee6ac-c42e-4d74-b06f-5724ac754fabso︠
M = matrix(5, 15, gcd)
M
︡f8a3124f-6c72-4df7-960e-927c8037a15e︡{"stdout":"[ 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14]\n[ 1  1  1  1  1  1  1  1  1  1  1  1  1  1  1]\n[ 2  1  2  1  2  1  2  1  2  1  2  1  2  1  2]\n[ 3  1  1  3  1  1  3  1  1  3  1  1  3  1  1]\n[ 4  1  2  1  4  1  2  1  4  1  2  1  4  1  2]\n"}︡{"done":true}
︠71b78e48-f304-46b5-8e7d-0d39c69fdaea︠









