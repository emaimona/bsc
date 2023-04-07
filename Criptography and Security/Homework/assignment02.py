import unittest
from math import gcd

def calculate4by4det():
    pass

def calc_det(a, b, c, d):
    return b*d - c*c - (a*d - c*b) + a*c - b*b


# mm = 0
# for i in range(10):
#     mm = gcd(mm, calc_det(x[i], x[i+1], x[i+2], x[i+3]))

def determine_modulus(random_samples):
    m = None
    return m

def determine_multiplier_and_increment(random_samples):
    a, c = None, None
    return a, c

class Lcg_spectral_analysis(unittest.TestCase):
    def __init__(self, *args, **kw_args):
        super(Lcg_spectral_analysis, self).__init__(*args, **kw_args)

        self.multiplier = 65539
        self.increment = 0 
        self.modulus = 2**31
        seed = 1

        sample_count = 2000
        self.random_samples = []
        for i in range(sample_count):
            seed = (self.multiplier * seed + self.increment) % self.modulus
            self.random_samples.append(seed)
    
    def test_determine_modulus(self):
        self.assertEqual(self.modulus, determine_modulus(self.random_samples))
    
    def test_determine_multiplier_and_increment(self):
        a, c = determine_multiplier_and_increment(self.random_samples)
        self.assertEqual(self.multiplier, a)
        self.assertEqual(self.increment, c)

if __name__ == '__main__':
    unittest.main()