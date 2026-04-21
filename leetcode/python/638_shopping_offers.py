INF = 10**9
class Solution:
    # TLE, here I should use dynamic programming or memorization
    def calculate_rec_prices(self, price: List[int], special: List[List[int]], needs: List[int], spec: int):
        # see if special applies and if it does call recursively
        works = True
        current_special = special[spec]
        aux_needs = copy.deepcopy(needs)
        for sp in range(1,len(current_special)-1):
            if needs[sp] > current_special[sp]:
                works = False
            aux_needs[sp] -= current_special[sp]
        if works:
            # if it is possible to apply, we take the offer and keep calling recursively
            total_price = current_special[-1]
            for i in range(1, len(price)):
                total_price += (aux_needs[i] * price[i])
            min_price = total_price
            for spec in range(1, len(special)):
                min_price = min(min_price, self.calculate_rec_prices(price, special, aux_needs, spec))
            return min_price 
        else:
            return INF
        

    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
        # primero la solucion sin ninguna special offer
        #precio total de cada unidad por cada cantidad
        #3 por 2 mas 2 por 5 = 16
        # como puedo evaluar las special offers?
        # 1er aproach todas con todas osea tomo una y defino recursivamente(factorial el T(n))
        total_price = 0
        for i in range(1, len(price)):
            total_price += needs[i] * price[i]
        min_price = total_price
        for spec in range(1, len(special)):
            min_price = min(min_price, self.calculate_rec_prices(price, special, needs, spec))



