import random
def dictranking(d):
    return sorted(d.keys(), key= lambda x:d[x], reverse= True)

def getpoints(l):
    return 3*l[0]+l[1]

def analyze_results(d):
    results = dict()
    for name in d.keys():
        results[name] = getpoints(d[name])
    print("Tournament results:")
    for team in dictranking(results):
        print(f"{team} {results[team]}")
    return None


class SportsLeague:
    def __init__(self, name):
        if not isinstance(name,str):
            raise TypeError
        if len(name) == 0:
            raise ValueError
        self.leaguename = name
        self.teams = dict()

    def __len__(self):
        return len(self.teams)

    def addteam(self, name, putere, force = False):
        name = str(name)
        putere = float(putere)
        force = bool(force)
        if len(name) == 0 or putere <= 0:
            raise ValueError
        if force == False and name in self.teams:
            raise KeyError
        self.teams[name] = putere

    def __repr__(self):
        ret = f"{self.leaguename}:\n"
        for x in dictranking(self.teams):
            ret += f" * {x}: {self.teams[x]}\n"
        return ret

    def _strength(self, name, homeboost):
        return self.teams[name]*1.2 if homeboost else self.teams[name]

    def match(self, t1, t2):
        s1 = self._strength(t1, True)
        s2 = self._strength(t2, False)
        m1 = (5*s1) // (s1+s2) + 1
        m2 = (5*s2) // (s1+s2) + 1
        return random.randint(0, m1), random.randint(0, m2)

    def tournament(self):
        d = dict()
        for x in self.teams.keys():
            d[x] = [0, 0, 0]
        for t1 in dictranking(self.teams):
            for t2 in dictranking(self.teams):
                if t1 == t2:
                    continue
                (m1, m2) = self.match(t1, t2)
                if m1 == m2:
                    d[t1][1] += 1
                    d[t2][1] += 1
                elif m1>m2:
                    d[t1][0] += 1
                    d[t2][2] += 1
                else:
                    d[t1][2] += 1
                    d[t2][0] += 1
        return d

    def odds(self, n):
        odd = {x:[0]*len(self) for x in self.teams.keys()}
        for i in range(n):
            tour = self.tournament()
            results = dict()
            for name in tour.keys():
                results[name] = getpoints(tour[name])
            for i,name in enumerate(dictranking(results)):
                odd[name][i] += 1
        for perc in odd.keys():
            odd[perc] = [x/n for x in odd[perc]]
        return odd



league = SportsLeague("The Calvinball World League")
league.teams = {'Shorts': 0.9, 'Talls': 1.5, 'Olds': 0.5, 'Mutants': 2.0}
#league.odds(100)


