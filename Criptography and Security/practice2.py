
from collections import Counter

# lines = ''
# with open('moby10b.txt') as f:
#     text = ''.join(f.readlines()).lower()
#     count = Counter(text)
#     print(count)

def encode(text, alphabet):
    return list(
        map(
            lambda char: alphabet.find(char),
            text
        )
    )


def decode(encoded_text, alphabet):
    return ''.join(
        map(
            lambda n: alphabet[n],
            encoded_text
        )
    )

def shift_decrypt(message, key):
    return decode(list(
        map(
            lambda el: (alphabet.index(el) -
                        alphabet.index(key)) % len(alphabet),
            list(message)
        )
    ), alphabet)


def shift_encrypt(message, key):
    return decode(
        list(
            map(
                lambda el: (alphabet.index(el) +
                            alphabet.index(key)) % len(alphabet),
                list(message)
            )
        )
    , alphabet)

alphabet_dict = {}
counter = 0

with open('moby10b.txt') as f:
    while True:
        ch = f.read(1).lower()
        if not ch:
            break

        counter += 1
        if ch in alphabet_dict:
            alphabet_dict[ch] += 1
        else:
            alphabet_dict[ch] = 1


alphabet = list(alphabet_dict.keys())
frequencies = list(map(lambda x: x / counter, alphabet_dict.values()))



text = '''In thoroughfares nigh the docks, any considerable seaport will
frequently offer to view the queerest looking nondescripts from
foreign parts.  Even in Broadway and Chestnut streets, Mediterranean
mariners will sometimes jostle the affrighted ladies.  Regent Street
is not unknown to Lascars and Malays; and at Bombay, in the Apollo
Green, live Yankees have often scared the natives.  But New Bedford
beats all Water Street and Wapping.  In these last-mentioned haunts
you see only sailors; but in New Bedford, actual cannibals stand
chatting at street corners; savages outright; many of whom yet carry
on their bones unholy flesh.  It makes a stranger stare. '''.lower()
 
key = alphabet[5]
cipher_text = shift_encrypt(text, key)

cipher_distribution = [0 for _ in frequencies]

for i in cipher_text:
    cipher_distribution[alphabet.index(i)] += 1

for i in range(len(cipher_distribution)):
    cipher_distribution[i] /= len(cipher_text)


def chi_square(qs, ps):
    return sum(((qs[i] - ps[i]) ** 2 ) / ps[i] for i in range(len(qs)))


min_index = None
min_score = 1e20
for shift in range(len(alphabet)):
    shifted_cipher_distribution = cipher_distribution[shift:] + cipher_distribution[:shift]
    score = chi_square(shifted_cipher_distribution, frequencies)

    if score < min_score:
        min_index = shift
        min_score = score

print(min_index)