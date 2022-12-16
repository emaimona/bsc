module HWExtra
import StdEnv


// Maimona Emanuel Nzinga
// Neptun: GAU5OE

:: Bank = AMEX | VISA | MASTERCARD

:: Account = {name :: String, issuer :: Bank, cardnumber :: Int, age :: Int}

/* There has been news of a fraud, where invalid credit cards are being used without being noticed.
Now the World bank would like to check the validity of the credit cards numbers' of every major bank.
Therefore make a function that will return invalid account's (name, issuer) pais from the array of accounts. 

Validation: 
1. check prefix and length
    AMEX: start with 34 or 37 and has 15 numbers.
    MasterCard: start with 51, 52, 53, 54, or 55 and has 16 numbers.
    Visa: start with 4539, 4556, 4916, 4532, 4929, 40240071, 4485, 4716 or 4 and has 13 or 16 numbers.
2. implement luhn algorithm (https://en.wikipedia.org/wiki/Luhn_algorithm
                            https://www.groundlabs.com/blog/anatomy-of-a-credit-card/)
                            
*/

toD :: Int -> [Int]
toD 0 = []
toD n = [(n rem 10): toD (n/10)]

toN :: [Int] Int -> Int
toN [] n = n
toN [x: xs] n = toN xs (n*10 + x)

PrefixAmex = [34, 37]
PrefixMasterCard = [51, 52, 53, 54, 55]
PrefixVisa = [4539, 4556, 4916, 4532, 4929, 40240071, 4485, 4716, 4]

instance == Bank
where
    (==) AMEX AMEX = True
    (==) VISA VISA = True
    (==) MASTERCARD MASTERCARD = True
    (==) _ _ = False 
    
    
checkPrefix :: Bank Int -> Bool
checkPrefix bank number
| bank == AMEX = isMember (toN (take 2 ( digits number)) 0) PrefixAmex && length (digits number) == 15
| bank == MASTERCARD = isMember (toN (take 2 ( digits number)) 0) PrefixMasterCard && length (digits number) == 16
| bank == VISA = (checkNdigits 4) || (checkNdigits 8) || (checkNdigits 1)   &&   (length (digits number) == 13 || length (digits number) == 16)
where

    digits x = reverse (toD x)
    checkNdigits n = isMember (toN (take n ( digits number)) 0) PrefixVisa
    

luhnAlgorithmOdd :: Int -> Bool
luhnAlgorithmOdd nbr = (sum firstP + sum thirdStep) rem 10 == 0
where
    firstP = [ x \\ x<-digits & y<-[0..] | y rem 2 == 0]
    secondP = [ x*2 \\ x<-digits & y<-[0..] | y rem 2 <> 0]
    thirdStep = flatten (map toD secondP)
    digits = reverse (toD nbr)

luhnAlgorithmEven :: Int -> Bool
luhnAlgorithmEven nbr = (sum secondP + sum thirdStep) rem 10 == 0
where
    firstP = [ x*2 \\ x<-digits & y<-[0..] | y rem 2 == 0]
    secondP = [ x \\ x<-digits & y<-[0..] | y rem 2 <> 0]
    thirdStep = flatten (map toD firstP)
    digits = reverse (toD nbr)

isGood :: Bank Int -> Bool
isGood bank nbr
| length (toD nbr) rem 2 == 0 = (checkPrefix bank nbr) && (luhnAlgorithmEven nbr)
= (checkPrefix bank nbr) && (luhnAlgorithmOdd nbr)

                        
invalid :: {Account} -> {(String, Bank)}
invalid accounts = {(acc.name, acc.issuer) \\ acc<-:accounts | not (isGood acc.issuer acc.cardnumber) }


Start = invalid {{name = "Sheldon", issuer = AMEX, cardnumber = 374245455400126, age = 30},{name = "Raj", issuer = AMEX, cardnumber = 378282246319905, age = 31} , {name = "Leonard", issuer = MASTERCARD, cardnumber = 378282246310005, age = 33} ,{name = "Penny", issuer = MASTERCARD, cardnumber = 552523340109903, age = 32} , {name = "Amy", issuer = VISA, cardnumber = 4917484589897107, age = 31}, {name = "Howard", issuer = VISA, cardnumber = 79927398713, age = 30}} 
// {("Raj", AMEX), ("Penny", MASTERCARD) ("Howard", VISA)} 

                
:: Tree a = Node a (Tree a) (Tree a) | Leaf

tree1 :: Tree Int
tree1 = (Node 1 (Node 2 (Node 4 Leaf Leaf)(Node 5 Leaf Leaf)) (Node 1 (Node 6 Leaf Leaf) Leaf))

tree2 :: Tree Int
tree2 = (Node 4 (Node 3 (Node 11 (Node 2 Leaf Leaf) Leaf) Leaf) (Node 0 (Node 2 (Node 13 (Node 15 Leaf Leaf) Leaf) Leaf) (Node 1 Leaf Leaf) ))

tree3 :: Tree Int
tree3 = (Node -1 (Node -3 (Node -11 (Node -2 Leaf Leaf) Leaf) Leaf) (Node -16 (Node -22 (Node -13 (Node -15 Leaf Leaf) Leaf) Leaf) (Node -100 Leaf (Node -1 Leaf Leaf)) ))


/* Given a binary tree return its level order traversal 

e.g 3 -> [3]
   / \
   9  20 -> [9,20]
  /   / \
  1  15 7 -> [1,15,7] => [[3], [9,20],[1,15,7]] */


:: Bag a :== [[Int]]

ins:: (Bag a) Int Int-> (Bag a)
ins [x:xs] pos val
| pos == 0 = [x++[val]: xs]
| length [x:xs] <= pos = [x:xs] ++ [[val]]
= [x: ins xs (pos - 1) val]


NbrLevel :: (Tree a) -> Int
NbrLevel Leaf = 0
NbrLevel (Node _ le ri) = 1 + max (NbrLevel le) (NbrLevel ri)

getLevel :: (Tree Int) Int Int -> [Int]
getLevel Leaf _ _ = []
getLevel (Node n le ri) index level 
| level == index = [n] ++ (getLevel le (index+1) level) ++ (getLevel ri (index+1) level)
= (getLevel le (index+1) level) ++ (getLevel ri (index+1) level)


levelOrder :: (Tree Int) -> [[Int]]
levelOrder tree = [getLevel tree 1 level \\ level<-[1..NbrLevel tree]]


//Start = levelOrder tree1 // [[1],[2,1],[4,5,6]]
//Start = levelOrder tree2 // [[4],[3,0],[11,2,1],[2,13],[15]]
//Start = levelOrder tree3 // [[-1],[-3,-16],[-11,-22,-100],[-2,-13,-1],[-15]]
//Start = levelOrder  (Node 3 (Node 9 (Node 1 Leaf Leaf) Leaf) (Node 20 (Node 15 Leaf Leaf) (Node 7 Leaf Leaf))) // [[3],[9,20],[1,15,7]]
