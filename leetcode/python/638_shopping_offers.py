import copy

class Solution:

    def special_raw_price(self, special, price):
        raw_price = 0
        for spec in range(len(special)-1):
            raw_price += price[spec] * special[spec]
        return raw_price

    def check_special_applies(self, price, needs, spec):
        for key in range(len(needs)):
            if spec[key] > needs[key]:
                return False
        return True

    def rec_shopping_offers(self, price, special, needs):
        if tuple(needs) in self.memo.keys():
            return self.memo[tuple(needs)]
        all_needs = 0
        #print("received needs")
        #print(needs)
        for key in range(len(needs)):
            all_needs += needs[key]
        if all_needs == 0:
            #print("all needs is ZERO")
            return 0
        # initial min is applying it with unit price
        initial_price = 0
        for key in range(len(needs)):
            initial_price += needs[key] * price[key]
        #print(F"initial price is {initial_price}")
        for spec in special:
            if self.check_special_applies(price, needs, spec):
                aux_needs = copy.deepcopy(needs)
                spec_price = spec[len(spec)-1]
                for key in range(len(needs)):
                    aux_needs[key] = needs[key] - spec[key]
                #print(f"call rec with needs {aux_needs}")
                rec_value = self.rec_shopping_offers(price, special, aux_needs)
                #print(f"rec_value {rec_value} spec_price {spec_price} special_raw_price {self.special_raw_price(spec, price)}")
                initial_price = min(initial_price,  rec_value + spec_price)
        #print(f"gonna return {initial_price} with needs {needs}")
        self.memo[tuple(needs)] = initial_price
        return initial_price

    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
        self.memo = {}
        filtered_special = []
        for spec in special:
            if self.check_special_applies(price, needs, spec):
                filtered_special.append(spec)
        return self.rec_shopping_offers(price, special, needs)
