import unittest


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


def vigenere_encrypt(text, key, alphabet):
    encoded_key = encode(key, alphabet)

    return decode(list(
        map(
            lambda obj: (obj[1] + encoded_key[obj[0] %
                         len(key)]) % len(alphabet),
            enumerate(encode(text, alphabet))
        )
    ), alphabet)


def vigenere_decrypt(cipher, key, alphabet):
    encoded_key = encode(key, alphabet)

    return decode(list(
        map(
            lambda obj: (obj[1] - encoded_key[obj[0] %
                         len(key)]) % len(alphabet),
            enumerate(encode(cipher, alphabet))
        )
    ), alphabet)


class Vigenere_test(unittest.TestCase):
    def __init__(self, *args, **kw_args):
        super(Vigenere_test, self).__init__(*args, **kw_args)

        self.alphabet = 'abcdefghijklmnopqrstuvwxyz, '
        self.text = 'egy aprocska kalapocska, benne csacska macska mocska'
        self.key = 'lusta dick'
        self.key2 = 'grabowsky'
        self.cipher = 'p,osaouweavurbakdxqmbcsr ahvpokwitcrnibwlwiba,pweavu'

    def test_encrypt(self):
        self.assertEqual(vigenere_encrypt(
            self.text, self.key, self.alphabet), self.cipher)
        self.assertNotEqual(vigenere_encrypt(
            self.text, self.key2, self.alphabet), self.cipher)

    def test_decrypt(self):
        self.assertEqual(vigenere_decrypt(
            self.cipher, self.key, self.alphabet), self.text)
        self.assertNotEqual(vigenere_decrypt(
            self.cipher, self.key2, self.alphabet), self.text)

    def test_end2end(self):
        self.assertEqual(vigenere_decrypt(vigenere_encrypt(
            self.text, self.key, self.alphabet), self.key, self.alphabet), self.text)


if __name__ == '__main__':
    unittest.main()
