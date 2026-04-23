INF = 10**9
class Solution:

    def _initialize_matrix(self, initial_cost, price):
        self.pd = []
        for i in range(0, len(price)+1):
            self.pd.append([0] * (len(price)+1))
        for i in range(0, len(price)+1):
            self.pd[i][0] = initial_cost
            self.pd[0][i] = initial_cost
        #print(self.pd)

    def calculate_rec_prices_pd(self, price: List[int], special: List[List[int]], needs: List[int], initial_cost:int):
        self._initialize_matrix(initial_cost, price)
        #print(self.pd)
        for spec in range(1, len(special)+1):
            #print(f"processing spec {spec-1}")
            spec_row = special[spec-1]
            #print(spec_row)
            spec_price = spec_row[len(spec_row)-1]
            for i in range(1,len(special)+1):# TODO check, perhaps y should have a custom range
                discount_price = 0
                # si needs es menor a special para alguno, solo tomamos el minimo
                offer_applies = True
                for offer_index in range(0, len(spec_row)-1):
                    if spec_row[offer_index] * i > needs[offer_index]:
                        offer_applies = False
                if not offer_applies:
                    self.pd[spec][i] = min(min(self.pd[spec-1][i-1], self.pd[spec-1][i]), self.pd[spec][i-1])
                else:
                    #sino, todo lo otro
                    for offer_index in range(0, len(spec_row)-1):
                        #print(f" offer_index {offer_index}")
                        #print(f"gonna add {spec_row[offer_index] * price[offer_index]} in offer_index {offer_index}")
                        discount_price += spec_row[offer_index] * price[offer_index]
                    
                    #print(f"discount price {discount_price} spec_price {spec_price}")
                    up_left = self.pd[spec-1][i-1] - discount_price + spec_price * i
                    up = self.pd[spec-1][i]
                    left = self.pd[spec][i-1]
                    if up_left < up and up_left < left:
                        self.pd[spec][i] = up_left
                        # print(f"updating {spec} {i} with up left")
                        # TODO update needs for this case
                    elif up < left:
                        self.pd[spec][i] = up
                        #print(f"updating {spec} {i} with up")
                        # update needs
                    else:
                        self.pd[spec][i] = left
                        print(f"updating {spec} {i} with left")
                        # update needs
            print(self.pd)
        print(self.pd)
        return self.pd[len(needs)][len(needs)]
                #print(self.pd)
        #print(self.pd)

    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
        # primero la solucion sin ninguna special offer
        #precio total de cada unidad por cada cantidad
        #3 por 2 mas 2 por 5 = 16
        # como puedo evaluar las special offers?
        # 1er aproach todas con todas osea tomo una y defino recursivamente(factorial el T(n))
        total_price = 0
        for i in range(0, len(price)):
            total_price += needs[i] * price[i]
        min_price = total_price
        return self.calculate_rec_prices_pd(price, special, needs, total_price)



