

alphabet = 'abcdef'


def convert_letters_to_numbers(letters):
    return list(
        map(
            lambda element: alphabet.index(element), letters
        )
    )


def convert_numbers_to_letters(numbers):
    return ''.join(list(
        map(
            lambda element: alphabet[element],
            numbers
        )
    ))


def shift_decrypt(message, key):
    return convert_numbers_to_letters(list(
        map(
            lambda el: (alphabet.index(el) -
                        alphabet.index(key)) % len(alphabet),
            list(message)
        )
    ))


def shift_encrypt(message, key):
    return convert_numbers_to_letters(
        list(
            map(
                lambda el: (alphabet.index(el) +
                            alphabet.index(key)) % len(alphabet),
                list(message)
            )
        )
    )


key = 'c'
letters = 'deadbeef'
encoded = shift_encrypt(letters, key)
decoded = shift_decrypt(encoded, key)
print(encoded)
print(decoded)


numbers = convert_letters_to_numbers(letters)


print(numbers)
print(convert_numbers_to_letters(numbers))
