︠42058e0c-d87b-4bde-8bc6-7e5272263efa︠
︡069f20e1-4787-4d77-a190-27e5aa33b416︡
︠6b3443ae-2447-4857-85bc-7c21726b5388i︠
%html
<p style="text-align: center;"><span style="font-size: large;"><strong>Application of Discrete Models Course &ndash; Lecture 1</strong></span></p>
<p style="text-align: justify;"><span style="font-size: medium;">Welcome to Application of Discrete Models. In the first worksheet you will learn to use the worksheet interface, play around with some of the functions available in Sage and see what symbolic calculation means. This worksheet also introduces some useful data types: lists, sets, tuples, dictionaries, vectors and matrices. In order to practice some of the things learnt, there are some exercises at the end.</span></p>
︡030c8cf4-9203-4857-a79e-66730e5b657a︡{"done":true,"html":"<p style=\"text-align: center;\"><span style=\"font-size: large;\"><strong>Application of Discrete Models Course &ndash; Lecture 1</strong></span></p>\n<p style=\"text-align: justify;\"><span style=\"font-size: medium;\">Welcome to Application of Discrete Models. In the first worksheet you will learn to use the worksheet interface, play around with some of the functions available in Sage and see what symbolic calculation means. This worksheet also introduces some useful data types: lists, sets, tuples, dictionaries, vectors and matrices. In order to practice some of the things learnt, there are some exercises at the end.</span></p>"}
︠1d41bb69-560f-4d2b-9a5e-b5e00701dfa0︠
︡1bdb148b-9582-4352-a6c6-b6f56536d542︡
︠169f7019-1927-432b-b2a0-1d61b3b1a261︠
3+4
︡7f1f5353-f638-4d9e-920f-f490870f9735︡
︠b751556d-76bb-47cb-8494-78f5d056a02c︠
︡f49b7b9b-797b-42e7-bd67-5a20852b5e85︡
︠bfbf3e7c-ae8c-4c93-841e-9798edce863di︠
%html
<p><span style="font-size: medium;">One can enter commands by typing into the rectangular cells and either pressing SHIFT+Enter or clicking on the evaluate button. Pressing Enter will add a line break within the cell.</span></p>
<p><span style="font-size: medium;">You can create new cells by clicking on the blue horizontal line appearing when you hover with the mouse at the top of a cell. Delete a cell by backspacing all its contents (be careful, this moves the cursor to the previous cell after deletion). </span></p>
<p><span style="font-size: medium;">You can create text cells by shift-clicking the blue line. Text cells allow some formatting and latex input between dollar signs. Try these actions.</span></p>
<p><strong><span style="font-size: medium;">Arithmetic&nbsp;</span></strong></p>
<p><strong></strong><span style="font-size: medium;">Arithmetic operations use the traditional signs: +, -, *, /. Exponentiation's sign is &circ;, and the remainder when you divide integers is denoted by %. Spaces within a line have no effect on the calculation. Use 'I' for complex numbers.</span></p>
︡a2ac9f75-acc9-4909-b8d6-f72e9a969621︡{"done":true,"html":"<p><span style=\"font-size: medium;\">One can enter commands by typing into the rectangular cells and either pressing SHIFT+Enter or clicking on the evaluate button. Pressing Enter will add a line break within the cell.</span></p>\n<p><span style=\"font-size: medium;\">You can create new cells by clicking on the blue horizontal line appearing when you hover with the mouse at the top of a cell. Delete a cell by backspacing all its contents (be careful, this moves the cursor to the previous cell after deletion). </span></p>\n<p><span style=\"font-size: medium;\">You can create text cells by shift-clicking the blue line. Text cells allow some formatting and latex input between dollar signs. Try these actions.</span></p>\n<p><strong><span style=\"font-size: medium;\">Arithmetic&nbsp;</span></strong></p>\n<p><strong></strong><span style=\"font-size: medium;\">Arithmetic operations use the traditional signs: +, -, *, /. Exponentiation's sign is &circ;, and the remainder when you divide integers is denoted by %. Spaces within a line have no effect on the calculation. Use 'I' for complex numbers.</span></p>"}
︠4311415c-aad2-4ef8-b41c-07ec5b738cd3︠
20+12, 200 -12, 200/12, 200*11
︡2a1ccf0c-6dc2-4767-ba96-953e400e49fd︡
︠51aa6570-60a5-4e1c-96dc-2aaa72b6972as︠
2^30 + 23
︡59b810cd-58b1-4c2f-a4a5-c21cd35b6d3c︡
︠8b895c65-23c9-4364-99f8-b9463a4f467ds︠
2^2000
︡aff3c8a2-e397-486f-af5a-180270663a80︡
︠219b5bb9-53cb-4f09-9817-cfb967b26f2as︠
(1+I)^12
︡ed43248b-4f2b-44a2-aed5-ff2c3422e21f︡
︠838fea1a-9f36-453f-a502-2f6005648b64i︠
%html
<p><strong><span style="font-size: medium;">Some commands usually found on a scientific pocket calculator</span></strong></p>
<p><span style="font-size: medium;">The commands found on typical scientific calculator mostly have the names one would expect.</span></p>

︡150feb5e-8cd8-46eb-a87f-649e8a82fdf9︡{"done":true,"html":"<p><strong><span style=\"font-size: medium;\">Some commands usually found on a scientific pocket calculator</span></strong></p>\n<p><span style=\"font-size: medium;\">The commands found on typical scientific calculator mostly have the names one would expect.</span></p>"}
︠82c025cc-a353-4296-a387-92e4ac44b7d8s︠
factorial(100)
︡d03a9e0e-2547-4f1c-8659-e4f2dbe71ff3︡
︠b48302ad-de26-4bcc-a223-59bd33506224︠
exp(3)
︡0d75c303-3482-496c-ad2f-e624dd1817dc︡
︠7fcbe1e1-9be1-4a41-89f1-e9b1431b820b︠
ln(exp(3))
︡5bc7435b-2ef9-4b05-8fde-06ef815494ef︡{"stdout":"3\n"}︡{"done":true}
︠b9b555f6-886b-4ddc-a3aa-cb16d67a31des︠
numerical_approx(pi, digits = 150)
︡42fbdd68-ce94-45b0-99e5-1fc8b8231ef0︡
︠8a7a95d9-0c02-4ae5-9b11-81cbddb15ac5s︠
solve(x^2-x-1 ==0, x )
︡a392e062-2046-4cc3-92ff-9616fce20e33︡
︠ed4ea65c-5628-4381-93d8-8ae5cf04d802i︠
%html
<p><span style="font-size: medium;"><strong>Some simple commands usually not present on calculators</strong></span></p>
<p><span style="font-size: medium;">Most built-in mathematical functionality is provided through functions. Function calls use parentheses.</span></p>

︡4e094a82-37f3-4f64-8897-d59c4794deb6︡{"done":true,"html":"<p><span style=\"font-size: medium;\"><strong>Some simple commands usually not present on calculators</strong></span></p>\n<p><span style=\"font-size: medium;\">Most built-in mathematical functionality is provided through functions. Function calls use parentheses.</span></p>"}
︠62d99687-0f9a-4d8c-b3f7-ed7a75cd37aeo︠

︡f6f70592-d608-429a-84fc-aeaad5d023ea︡
︠8496aa1f-a01f-403c-9320-256a5bdf83a2s︠
var('x, y, z')
solve([x+3==y, x+5==2*z, y-1 == z], x, y, z)
︡1aa46e1d-da83-4c52-bba2-9f8effb9fe47︡
︠868abe6a-bc51-4282-a5a1-b1f94e22792es︠
plot(sin(x), x, -15, 15, figsize = 3)
︡2834aebc-d71a-427e-bb93-4a49d4621f36︡
︠27ba3433-5fed-4d35-b3e4-1368022dafdds︠
is_prime(4087202107563496330961009)
︡9619e50f-b628-495a-b817-49d2d490fa73︡
︠9d3d953a-3acc-4eb7-bd68-9007f331d594s︠
next_prime(34923947239487382472308)
︡b28d12b9-46c3-4f23-9aa8-6b872ac7dbf7︡
︠dc92cc52-1176-4686-861b-3e57b027cf3ds︠
nth_prime(2)
︡8a7ce682-0d1b-4169-8760-cce1c12adbe3︡
︠ef976a10-073c-43f1-b9e2-0c0e594e5815︠
prime_pi(1000)
︡ce7e1720-0478-465c-b140-b34baaaf78a6︡
︠815526ae-2121-4fbf-b754-9aa8dbe8ddc3s︠
factor(555555533333333333333333333333333333335556)
︡c5ca6b41-6f70-434e-99c3-3fffdeda173a︡
︠791aa193-21d2-4149-88bf-8ea4759c2de0i︠
%html
<p><span style="font-size: medium;"><strong>Assignments.</strong></span></p>
<p><span style="font-size: medium;">One can save numbers, functions etc. into variables. Assignment operator is '=', equality is checked with '=='. Multiple assignments are possible. Variable names are case sensitive.</span></p>
︡1f39f809-ac64-48c6-80db-008ddc9edee2︡{"done":true,"html":"<p><span style=\"font-size: medium;\"><strong>Assignments.</strong></span></p>\n<p><span style=\"font-size: medium;\">One can save numbers, functions etc. into variables. Assignment operator is '=', equality is checked with '=='. Multiple assignments are possible. Variable names are case sensitive.</span></p>"}
︠dbb02598-8b53-4c62-b8ee-bd505601d160s︠
a = 17
a^2
︡6a5a193a-c7dc-4728-b207-e1c53df55592︡
︠41e52205-c94a-448a-817b-95707849bd00︠
i, j, k = 7, 8, 9
︡df2277bb-5e55-4a23-8a64-11b51df91333︡
︠7fb541a5-bb44-4a21-aa61-0c841d28fe18s︠
i, j = j, i
i, j, k
︡87d761af-7ca0-4057-aa45-18a043940733︡
︠56f8a35a-600f-4783-8208-b53a202766acs︠
aAaA = 7
AaAa = 8
︡8a593fd9-9fc2-4fa5-9d7d-ddd0ccfe3a3f︡
︠57378bb0-7808-4610-b5d5-bf842282e739s︠
aAaA == AaAa
︡a2b230cf-53db-4721-91a6-02d6b65cf5df︡
︠1e553061-3938-4c2a-a5ac-b8d1b31ac96ci︠
%html
<p><strong><span style="font-size: medium;">Lists</span></strong></p>
<p><span style="font-size: medium;">We now consider some data types that can contain other data.&nbsp;</span></p>
<p><span style="font-size: medium;">Lists can be created by putting values into brackets. Accessing elements is also achieved by barckets. Indexing starts with 0.</span></p>
︡abec7be6-d580-46a9-ac8c-be6d35734211︡{"done":true,"html":"<p><strong><span style=\"font-size: medium;\">Lists</span></strong></p>\n<p><span style=\"font-size: medium;\">We now consider some data types that can contain other data.&nbsp;</span></p>\n<p><span style=\"font-size: medium;\">Lists can be created by putting values into brackets. Accessing elements is also achieved by barckets. Indexing starts with 0.</span></p>"}
︠aa35e67d-9032-4fd6-ae8a-10c97d24a912s︠
L=[4, 5, 6]
︡45ef35ba-e2fa-442e-bfd9-cfa0b5eb1aa5︡{"done":true}
︠ac929696-a34e-4591-8a19-482af0712927s︠
L[0]
︡d0cd0bd3-0d12-46cc-9dd6-9f09d4bc7437︡
︠76519379-90d8-450e-a015-92931e66cde7s︠
L[-1]
︡0e89ffc4-31e6-4b92-a2d3-03df051420de︡
︠5349cb06-2e3d-4ad5-aa84-cebd296f494ds︠
L += [100, 200, 300]
︡22365122-8d59-41a9-b227-2be879692e80︡{"done":true}
︠7c0877c0-7586-4748-b437-fa17bfddb3f3s︠
L
︡c07d3cca-42f3-4bbb-92fb-5b5dec751228︡
︠7eb28458-1e92-4a98-9068-8d9f0e36a29as︠
L[0:3]
︡2bd91c42-4c42-4a0b-8fd8-7a263861d81b︡
︠5ffd62eb-1807-4baf-9d0d-5d65d3f18c4es︠
L = [1..10]
︡7631de3e-8442-4531-81b8-9c5c60532882︡{"done":true}
︠75b4fbbf-1b55-4829-900e-858122e640c2︠
L
︡7a8f2670-b7c9-43f1-8841-c7f9ebf98feb︡
︠33cd5691-1855-45f6-8756-5afe88ca466cs︠
range(1, 11)
︡b157cbe4-fc6a-4433-9da1-3c079a54ff82︡
︠a259a435-a366-43bf-b350-74158a1c5e6as︠
L2 = [i^2 for i in range(1, 11)]
L2
︡14e88902-0af9-4345-a76f-9b4ed4873a56︡
︠9bf5a063-9e60-4b4f-b2ea-1ac25782ec89s︠
L
L3 = [i-1 for i in L]
L3
︡cf6eb066-a650-4ea6-be4b-c3192ca7519d︡
︠a13e852c-606f-421a-bfac-d4f73993323fs︠
# Note the order of the two uses of 'for'
[(i, j) for i in range(1, 5) for j in range(i, i+2)]
︡fe675174-32d6-4191-af7b-5885d03f694b︡
︠499b14f1-2981-499a-ae58-4ec69470de0es︠
# One can add conditions to a list comprehension
L = [i for i in range(1, 40) if is_prime(i)]
L
︡06d404d7-fb47-4543-9260-febd920a2b0a︡
︠df857e08-3f33-4895-b99c-a60cd765ac57s︠
10 in L
︡d9d63473-d5b0-4118-8065-1a67873f4b35︡
︠914a62c1-ca54-4b95-9864-3da70b390ee6︠

︡6cbe3917-790a-447f-a2ec-f15d37c38d5d︡
︠def131c5-d716-424e-9678-4f5004e10f55s︠
L2.index(25)
︡5c441fb0-a27d-4bbe-b3a0-5f99bb687316︡
︠af3418e6-ac6b-410d-aa62-9b5e08546fa8s︠
L
︡ccfa9d22-be0f-49a8-b539-78110517bc72︡
︠698f19a1-e25c-4b94-b09d-615867bdc06bs︠
sum(L)
︡7cc88946-2485-4408-ba2a-52ed64381bd6︡
︠ed1dda3e-1678-44e4-a8f7-746b8f428199s︠
L = [i for i in range(1,100) if is_prime(i)]
L
︡d19478b3-c1df-4b0f-8a32-9928e58fc4e6︡
︠8dee4a0b-dd49-459d-b661-9df00c23d642︠
# Combine conditions with 'and', 'or', 'not'
L = [i for i in range(1,100) if is_prime(i) and i%5 == 1]
L
︡0bb5cf9d-c6a6-47ce-ae58-53b2bdd7863a︡
︠7f42c6e0-6279-4324-911b-329b22ced21a︠
len(L)
︡e7c93784-b2d3-4663-89d4-2a9d12896732︡
︠0bff045f-0183-4dd7-9784-4d75b7394770i︠
%html
<p><span>Here are some exercises of various difficulty so that you can try some of the things learnt above.</span></p>
<p><span>1. Calculate $\pi^2/6$ to 200 decimal places.</span></p>
<p><span>2. Factor your student ID number.</span></p>
<p><span>3. Create a list of the first 100 prime numbers and calculate their sum.</span></p>
<p>&nbsp;</p>
︡3fab73fa-0a59-4cc8-a4bf-ceb06e009c58︡{"done":true,"html":"<p><span>Here are some exercises of various difficulty so that you can try some of the things learnt above.</span></p>\n<p><span>1. Calculate $\\pi^2/6$ to 200 decimal places.</span></p>\n<p><span>2. Factor your student ID number.</span></p>\n<p><span>3. Create a list of the first 100 prime numbers and calculate their sum.</span></p>\n<p>&nbsp;</p>"}
︠e12054ed-c1f4-4c5e-a4a0-c6aae4e98329︠









