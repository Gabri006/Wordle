#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "conio.h"
#include "lib.h"


int main ()
{
    /* insieme di parole delle quali ne verra' scelta una per essere la parola da indovinare */
    char matWord[3007][MAXTRY] = {"abaco", "abano", "abate", "abbai", "abbia", "abela", "abele", "abete", "abeti", "abile", "abili", "abita", "abiti", "abito", "abusa", "abusi", "abuso", "acaro", "aceri", "acero", "aceti", "aceto", "acida", "acide", "acidi", "acido", "acqua", "acque", "acume", "acumi", "acuto", "adagi", "adama", "adamo", "adana", "addii", "addio", "adele", "adelo", "adige", "adino", "aduni", "aduno", "aerea", "aeree", "aerei", "aereo", "afosa", "afose", "afosi", "afoso", "agape", "agata", "agato", "agave", "aggio", "agile", "agili", "agita", "agite", "agiti", "agito", "agiva", "agivi", "agivo", "aglio", "agone", "agoni", "agora", "aguti", "aguto", "ahime", "aiuta", "aiuti", "aiuto", "aizza", "aizzi", "aizzo", "alare", "alata", "alate", "alati", "alato", "album", "alcol", "alghe", "alias", "alibi", "alice", "alina", "alita", "aliti", "alito", "alone", "aloni", "altra", "altre", "altri", "altro", "alvei", "alveo", "alzai", "amaca", "amara", "amare", "amari", "amaro", "amata", "amate", "amati", "amato", "amava", "amavi", "amavo", "ambii", "ambra", "ameba", "ameno", "amica", "amici", "amico", "amido", "amore", "amori", "ampia", "ampie", "ampio", "ampli", "anche", "ancia", "andai", "aneli", "anglo", "anice", "anief", "anima", "anime", "animi", "animo", "anita", "anito", "annua", "annue", "annui", "annuo", "ansia", "ansie", "antro", "anubi", "aorta", "aosta", "apice", "apici", "apnea", "appai", "appia", "appio", "apple", "aprii", "araba", "arabe", "arabi", "arabo", "arano", "arata", "arate", "arati", "arato", "arava", "aravi", "aravo", "archi", "arcua", "arcui", "arcuo", "ardea", "ardii", "ardui", "arduo", "arena", "arida", "aride", "aridi", "arido", "armai", "aroma", "aromi", "arpia", "arpie", "array", "aruba", "asado", "ascia", "ascii", "ascis", "asilo", "asina", "asine", "asini", "asino", "aspra", "aspre", "aspri", "aspro", "assai", "asset", "astio", "astra", "astri", "astro", "atena", "atene", "atomi", "atomo", "atrio", "attua", "attui", "attuo", "audio", "aurea", "aureo", "avana", "avara", "avare", "avari", "avaro", "avena", "avere", "averi", "avete", "aveva", "avevi", "avevo", "avida", "avide", "avidi", "avido", "avrai", "avrei", "avuto", "avvia", "avvii", "avvio", "azoto", "babbi", "babbo", "bacca", "bacco", "bachi", "bacia", "bacio", "bacon", "badai", "badia", "badie", "baffi", "baffo", "bagna", "bagni", "bagno", "baita", "baite", "baldo", "balia", "balie", "balla", "balle", "balli", "ballo", "balza", "balzi", "balzo", "bamba", "banca", "banco", "banda", "bande", "bando", "banjo", "barai", "barba", "barbe", "barbo", "barca", "barde", "bardi", "bardo", "barra", "barre", "barri", "barro", "basco", "basic", "bassa", "basse", "bassi", "basso", "basta", "basti", "basto", "batch", "batta", "batte", "batti", "batto", "baule", "bauli", "bazar", "beata", "beate", "beati", "beato", "beava", "beavi", "beavo", "becco", "beffa", "beffi", "beffo", "beige", "belai", "belga", "belgi", "bella", "belle", "belli", "bello", "belva", "belve", "benda", "bende", "benin", "beota", "beoti", "berna", "berta", "berto", "betta", "betto", "bighe", "bimba", "bimbe", "bimbi", "bimbo", "bingo", "bioma", "birra", "birre", "bisca", "bivio", "blues", "blusa", "board", "bocca", "bocce", "boemo", "bolla", "bolle", "bolli", "bollo", "bomba", "bombe", "bonus", "bonzi", "bonzo", "bordi", "bordo", "borea", "borgo", "boria", "boris", "borsa", "borse", "bosco", "botta", "botte", "botti", "botto", "boxer", "bozza", "bozze", "brace", "braga", "brama", "brame", "brami", "bramo", "brand", "brano", "brave", "bravi", "bravo", "brema", "breve", "brevi", "briga", "brodi", "brodo", "bromo", "bruci", "bruco", "bruna", "brune", "bruni", "bruno", "brute", "bruto", "bucai", "bucce", "buche", "buchi", "budda", "buffa", "buffe", "buffi", "buffo", "bugia", "bugie", "bulbi", "bulbo", "bulla", "bulle", "bulli", "bullo", "buona", "buone", "buoni", "buono", "burla", "burle", "burli", "burlo", "burri", "burro", "bussa", "bussi", "busso", "busta", "buste", "busto", "butta", "butti", "butto", "cacao", "cacce", "cacci", "cache", "cachi", "cacio", "cadde", "caddi", "caini", "calca", "calce", "calci", "calco", "calda", "calde", "caldi", "caldo", "calli", "callo", "calma", "calme", "calmi", "calmo", "calva", "calve", "calvi", "calvo", "calza", "calze", "calzi", "calzo", "cambi", "cameo", "campi", "campo", "canna", "canne", "canta", "canti", "canto", "cappa", "cappe", "capra", "capre", "capta", "capti", "capto", "cargo", "caria", "carie", "carlo", "carne", "carni", "carpa", "carpe", "carpi", "carri", "carro", "carta", "carte", "casca", "casco", "cassa", "casse", "casta", "caste", "casti", "casto", "catia", "causa", "cause", "causo", "cauta", "caute", "cauti", "cauto", "cavia", "cavie", "ceche", "cechi", "cedra", "cedri", "cedro", "ceffi", "ceffo", "celia", "cella", "celle", "celta", "cenci", "cenni", "cenno", "cento", "ceppi", "ceppo", "cerca", "cerco", "certa", "certe", "certi", "certo", "cerva", "cervi", "cervo", "cesta", "ceste", "cesti", "cesto", "chele", "chili", "chilo", "ciano", "cicca", "cicco", "cicli", "ciclo", "cieca", "cieco", "cieli", "cielo", "cifra", "cifre", "cigni", "cigno", "cinse", "cinsi", "cinta", "cinte", "cinti", "cinto", "cipro", "circa", "ciste", "cisti", "clama", "clami", "clara", "claro", "clava", "clero", "clima", "clock", "clona", "clone", "cloni", "cloro", "cloud", "clown", "coach", "cobra", "cocca", "cocci", "cocco", "coesa", "coese", "coesi", "coeso", "cogli", "colei", "colga", "colgo", "colla", "colle", "colli", "colma", "colme", "colmi", "colmo", "colpa", "colpe", "colpi", "colpo", "colse", "colsi", "colta", "colte", "colti", "colto", "colui", "conca", "congo", "conia", "conio", "conta", "conte", "conti", "conto", "copia", "copie", "copio", "coppa", "coppe", "corda", "corde", "corea", "corna", "corni", "corno", "corpi", "corpo", "corra", "corre", "corri", "corro", "corsa", "corse", "corsi", "corso", "corta", "corte", "corti", "corto", "corvi", "corvo", "cosca", "cosce", "cosma", "cosmi", "cosmo", "costa", "coste", "costi", "costo", "cotta", "cotte", "cotti", "cotto", "cover", "cozza", "cozze", "crani", "crash", "creai", "creda", "crede", "credi", "credo", "crema", "creme", "crepa", "crepe", "crepi", "crepo", "creta", "crisi", "croce", "croci", "cruda", "crude", "crudi", "crudo", "crune", "cucco", "culla", "culli", "culto", "cuneo", "cuoca", "cuoco", "cuoio", "cuore", "cuori", "curai", "curdi", "curdo", "curia", "curie", "curva", "curve", "curvi", "curvo", "dacia", "dafne", "daghe", "dagli", "daini", "daino", "daisy", "dalla", "dalle", "dallo", "danni", "danno", "dante", "danza", "danze", "danzi", "danzo", "dardi", "dardo", "dario", "debug", "degli", "degna", "degne", "degni", "degno", "delia", "delio", "della", "delle", "dello", "delta", "densa", "dense", "densi", "denso", "dente", "denti", "derby", "desti", "desto", "detta", "dette", "detti", "detto", "diana", "diari", "dieci", "diego", "dieta", "diete", "dighe", "diodi", "diodo", "dirai", "direi", "disco", "disse", "dissi", "dista", "disti", "disto", "ditta", "ditte", "docce", "dogma", "dogmi", "dolce", "dolci", "donai", "donna", "donne", "doppi", "dorai", "dorma", "dorme", "dormi", "dormo", "dorsi", "dorso", "dosai", "dossi", "dosso", "dotai", "dotta", "dotte", "dotti", "dotto", "drago", "drink", "drone", "druso", "dubai", "dubbi", "duchi", "duomo", "durai", "ebano", "ebete", "ebeti", "ebola", "ebreo", "edera", "edile", "edili", "edita", "editi", "edito", "egizi", "eleva", "elevi", "elevo", "elica", "elisa", "elite", "elogi", "eluda", "elude", "eludi", "eludo", "emana", "emani", "emano", "emiri", "emiro", "emise", "emisi", "emoji", "empio", "emula", "emuli", "emulo", "ennia", "ennio", "entra", "entri", "entro", "epica", "epico", "epoca", "erano", "erede", "eredi", "erica", "erika", "erina", "ermes", "ernia", "ernie", "eroda", "erode", "erodi", "erodo", "eroga", "erogo", "erosa", "erose", "erosi", "eroso", "esala", "esali", "esalo", "esame", "esami", "esano", "esche", "esiga", "esige", "esigo", "esile", "esili", "esima", "esita", "esiti", "esito", "esodi", "esodo", "esula", "esule", "esuli", "esulo", "etera", "etere", "eteri", "etica", "etici", "etico", "etile", "etnia", "etnie", "evada", "evadi", "evado", "evasa", "evase", "evasi", "evaso", "evita", "eviti", "evito", "evoca", "evoco", "extra", "fabia", "fabio", "facce", "faggi", "faida", "faina", "faine", "falce", "falci", "falco", "falda", "falde", "falla", "falli", "fallo", "falsa", "falsi", "falso", "fango", "fanno", "fanti", "farad", "farai", "farro", "farsa", "farse", "farsi", "fasce", "fasci", "fatte", "fatti", "fatto", "fauci", "fauna", "fauni", "fauno", "fecce", "felce", "felpa", "felpe", "feria", "ferie", "ferma", "ferme", "fermi", "fermo", "ferri", "ferro", "fesse", "fesso", "festa", "feste", "fetta", "fette", "feudi", "feudo", "fiaba", "fiabe", "fiala", "fiata", "fiati", "fiato", "fibra", "fibre", "ficca", "ficco", "fiche", "fichi", "fieni", "fieno", "fiera", "fiere", "fieri", "fiero", "figli", "finga", "finge", "fingi", "fingo", "finse", "finsi", "finta", "finte", "finti", "finto", "fioco", "fiore", "fiori", "firma", "firme", "firmi", "firmo", "fisco", "fissa", "fisse", "fissi", "fisso", "fitta", "fitte", "fitto", "fiume", "fiumi", "fiuta", "fiuti", "fiuto", "flora", "fobia", "fobie", "foche", "fogli", "fogna", "fogne", "folla", "folle", "folli", "folto", "fonde", "fondi", "fonte", "fonti", "forai", "forca", "forma", "forme", "formi", "formo", "forni", "forse", "forte", "forum", "forza", "forze", "forzi", "forzo", "fossa", "fosse", "fossi", "fosso", "foste", "fosti", "frame", "frana", "frane", "frani", "frase", "frasi", "frate", "frati", "frena", "freni", "freno", "fresa", "frese", "fresi", "freso", "frida", "frido", "frigo", "frode", "frodi", "frodo", "fruga", "frugo", "fugga", "fugge", "fuggi", "fuggo", "fughe", "fughi", "fummo", "fungo", "fuoco", "fuori", "furba", "furbe", "furbi", "furbo", "furia", "furie", "furti", "furto", "fusti", "fusto", "gabon", "gaffe", "galli", "gallo", "gamba", "gambe", "gambi", "gambo", "gamma", "ganci", "ganzi", "ganzo", "garbo", "garza", "garze", "gasai", "gassi", "gatta", "gatte", "gatti", "gatto", "gazza", "gazze", "gechi", "gelai", "gelso", "gemma", "gemme", "genia", "genio", "genoa", "gente", "genti", "gergo", "germe", "germi", "gessi", "gesso", "gesta", "gesti", "gesto", "getta", "getti", "getto", "ghana", "ghiri", "ghiro", "ghisa", "giada", "giara", "giare", "gilda", "gioca", "gioco", "giogo", "gioia", "gioie", "giova", "giove", "giovi", "giovo", "girai", "giura", "giuro", "giusy", "gleba", "globi", "globo", "gnoma", "gnomi", "gnomo", "gobba", "gobbi", "gobbo", "gocce", "goffa", "goffe", "goffi", "goffo", "golfi", "golfo", "golia", "golpe", "gomma", "gomme", "gommi", "gonfi", "gonna", "gonne", "gradi", "grado", "grana", "grano", "grata", "grate", "grato", "grave", "gravi", "greca", "greci", "greco", "grevi", "grida", "gridi", "grido", "grigi", "grumi", "grumo", "guaio", "gufai", "guida", "guide", "guidi", "guido", "guisa", "gulag", "gusta", "gusti", "gusto", "haiti", "hanno", "henry", "hertz", "hippy", "hobby", "hotel", "humus", "iarda", "icaro", "icona", "icone", "idaho", "ideai", "idoli", "idolo", "igino", "igloo", "ilare", "imita", "imiti", "imito", "inail", "inala", "inali", "inalo", "inane", "india", "indio", "inizi", "input", "inter", "invii", "invio", "ioana", "iodio", "irene", "iride", "iridi", "irpef", "isaia", "iside", "islam", "isola", "isole", "isoli", "isolo", "issai", "istat", "italo", "itera", "iteri", "itero", "ivana", "ivano", "jeans", "jolly", "joule", "kabul", "kanji", "kappa", "karma", "kayak", "kebab", "kenya", "koala", "kyoto", "lacca", "lacci", "lacco", "ladra", "ladre", "ladri", "ladro", "laghi", "laica", "laici", "laico", "lampi", "lampo", "lance", "lanci", "landa", "lando", "lapis", "larga", "largo", "larva", "larve", "lasci", "lasco", "laser", "latta", "latte", "latti", "latto", "lauda", "laudi", "laudo", "laura", "lauro", "lauta", "laute", "lavai", "lazio", "lazzo", "leale", "leali", "lecce", "lecco", "legai", "legga", "legge", "leggi", "leggo", "leghe", "leghi", "legna", "legni", "legno", "lella", "lello", "lenta", "lente", "lenti", "lento", "lenza", "lenze", "leona", "leone", "leoni", "lepre", "lepri", "lesta", "leste", "lesti", "lesto", "letta", "lette", "letti", "letto", "levai", "liana", "liane", "liasi", "libia", "libra", "libri", "libro", "licei", "liceo", "licia", "licio", "lidia", "lieta", "liete", "lieti", "lieto", "lieve", "lievi", "lilla", "lillo", "limai", "limbo", "lince", "linci", "linda", "lindo", "linfa", "lisca", "lisce", "lisci", "lista", "liste", "litio", "litri", "litro", "liuti", "liuto", "livia", "livio", "lobby", "lochi", "loghi", "login", "lonza", "losca", "losco", "lotta", "lotte", "lotto", "lucca", "lucia", "lucio", "luigi", "lunga", "lungi", "lungo", "luogo", "lutti", "lutto", "macao", "madre", "madri", "maghi", "magia", "magie", "magma", "magno", "magra", "magre", "magri", "magro", "malta", "mamma", "mamme", "manca", "manco", "manda", "mandi", "mando", "manga", "mangi", "mango", "mania", "manie", "manna", "manta", "mante", "manti", "manto", "manzo", "mappa", "mappe", "mappi", "mappo", "marca", "marce", "marci", "marco", "marea", "maree", "mario", "marmi", "marmo", "marta", "marte", "marzo", "massa", "masse", "matta", "matte", "matti", "matto", "mauro", "mazza", "mazzi", "mazzo", "media", "medie", "medio", "melma", "mensa", "mense", "menta", "mente", "menti", "mento", "merce", "merci", "merla", "merli", "merlo", "messa", "messe", "messi", "messo", "mesta", "meste", "mesti", "mesto", "metal", "meteo", "metri", "metro", "metta", "mette", "metti", "metto", "mezza", "mezze", "mezzi", "mezzo", "miami", "micia", "micie", "micio", "micro", "miele", "mieli", "migra", "migri", "migro", "mille", "milza", "milze", "mimai", "mimma", "mimmo", "minai", "minsk", "miope", "mirai", "mirca", "mirco", "mirio", "mista", "miste", "misti", "misto", "mixer", "modem", "moira", "molla", "molle", "molli", "mollo", "molta", "molte", "molti", "molto", "mondi", "mondo", "monte", "monti", "monza", "morbo", "morra", "morsa", "morse", "morsi", "morso", "mosca", "mosce", "mosci", "mosco", "mossa", "mosse", "mossi", "mosso", "motel", "motti", "motto", "mouse", "mucca", "muffa", "multa", "multe", "multo", "munto", "muova", "muove", "muovi", "muovo", "murai", "musei", "museo", "mutai", "mutua", "mutue", "mutui", "mutuo", "nabbo", "nadia", "nafta", "nalda", "naldo", "nanda", "nando", "narra", "narri", "narro", "nasca", "nasce", "nasci", "nasco", "negai", "neghi", "negli", "nella", "nelle", "nello", "nepal", "nereo", "nervi", "nervo", "netta", "nette", "netti", "netto", "niger", "ninfa", "ninja", "ninna", "ninni", "nocca", "noemi", "nokia", "nonna", "nonne", "nonni", "nonno", "norma", "norme", "normo", "notai", "notte", "notti", "nozze", "nulla", "nullo", "nuora", "nuore", "nuoro", "nuota", "nuoti", "nuoto", "nuova", "nuove", "nuovi", "nuovo", "nutra", "nutre", "nutri", "nutro", "nylon", "oblii", "oblio", "occhi", "odiai", "odina", "odino", "odora", "odore", "odori", "odoro", "offro", "olbia", "oliai", "oliva", "olivo", "oltre", "ombra", "ombre", "ombro", "omega", "omero", "omini", "omino", "omise", "omisi", "onlus", "onora", "onore", "onori", "opaca", "opaco", "opera", "opere", "operi", "opero", "optai", "orafo", "orale", "orari", "orata", "orche", "orchi", "orfeo", "ormai", "ornai", "osaka", "osata", "osate", "osati", "osato", "osava", "osavi", "osavo", "oscar", "ossea", "ossee", "ossei", "osseo", "ossia", "ostia", "otaku", "otite", "ovaia", "ovaie", "ovale", "ovali", "ovari", "ovest", "ovile", "ovili", "ovina", "ovine", "ovini", "ovino", "ovvia", "ovvie", "ovvio", "oziai", "ozono", "pacai", "pacca", "pacco", "padre", "padri", "padua", "paese", "paesi", "pagai", "paghe", "paghi", "palco", "palio", "palla", "palle", "palma", "palme", "palmi", "palmo", "panca", "panda", "panna", "panni", "panno", "paola", "paolo", "pappa", "pappi", "pappo", "parco", "parla", "parli", "parlo", "parma", "parte", "parti", "parto", "passa", "passi", "passo", "pasta", "pasti", "pasto", "patti", "patto", "paura", "paure", "pausa", "pause", "pavia", "pazza", "pazze", "pazzi", "pazzo", "pegno", "pelai", "pelle", "pelli", "penai", "penna", "penne", "penny", "pensa", "penso", "peone", "peppa", "perda", "perde", "perdi", "perdo", "perla", "perno", "persa", "perse", "persi", "perso", "pesca", "pesce", "pesci", "petra", "petti", "petto", "pezza", "pezze", "pezzi", "pezzo", "piada", "piaga", "piago", "piana", "piane", "piani", "piano", "picca", "picco", "piede", "piedi", "piega", "piena", "piene", "pieni", "pieno", "piera", "piero", "pigia", "pigio", "pigli", "pigna", "pigra", "pigre", "pigri", "pigro", "pinna", "pinne", "pinza", "pinze", "pista", "piste", "pitta", "pitto", "piuma", "piume", "pixel", "pizza", "pizze", "placa", "placo", "plagi", "plani", "plano", "plebe", "plebi", "plico", "poche", "pochi", "podio", "poema", "poeta", "poeti", "poker", "polli", "pollo", "polpa", "polpe", "polpi", "polpo", "polsi", "polso", "ponga", "pongo", "ponte", "ponti", "poppa", "poppe", "porgo", "porta", "porte", "porti", "porto", "posso", "posta", "poste", "posti", "posto", "potai", "pozza", "pozze", "pozzi", "pozzo", "praga", "prato", "prave", "preda", "prede", "predi", "predo", "prega", "pregi", "prego", "prema", "preme", "premi", "premo", "presa", "prese", "preso", "prete", "preti", "previ", "prima", "prime", "primi", "primo", "priva", "prive", "privi", "privo", "proda", "prode", "prodi", "prole", "prosa", "prova", "prove", "provi", "provo", "proxy", "psico", "puffo", "pugni", "pugno", "pulce", "pulci", "pulsa", "pulsi", "pulso", "punta", "punte", "punti", "punto", "purga", "purgo", "puzza", "puzze", "puzzi", "puzzo", "qatar", "quale", "quali", "quasi", "quota", "quote", "quoti", "quoto", "radar", "radio", "raggi", "ragni", "ragno", "rally", "rampa", "ranch", "rango", "raoul", "rapii", "rasoi", "raspa", "raspi", "raspo", "rasta", "ratea", "ratei", "rateo", "ratio", "ratti", "ratto", "rauco", "razza", "razze", "razzi", "razzo", "reale", "reali", "reame", "reati", "reato", "rebus", "recai", "rechi", "regga", "regge", "reggi", "reggo", "regia", "regie", "regio", "regna", "regni", "regno", "relax", "remai", "rendo", "renna", "renne", "renzo", "resta", "resti", "resto", "retro", "retta", "rette", "retti", "retto", "riama", "riami", "riamo", "ricca", "ricce", "ricci", "ricco", "rieti", "rigai", "righe", "righi", "rimai", "rione", "rioni", "rissa", "risse", "rissi", "risso", "ritma", "ritmi", "ritmo", "ritto", "riusa", "riusi", "riuso", "rizzi", "rizzo", "robot", "rocca", "rocce", "rocco", "roghi", "rogna", "rogne", "rolla", "rolli", "rollo", "romba", "rombi", "rombo", "romea", "romeo", "rompa", "rompe", "rompi", "rompo", "ronda", "ronfa", "ronfi", "ronfo", "ronin", "roseo", "rospi", "rospo", "rossa", "rosse", "rossi", "rosso", "rotta", "rotte", "rotti", "rotto", "round", "rozza", "rozze", "rozzi", "rozzo", "rubai", "ruben", "rublo", "rugby", "rughe", "rulla", "rulli", "rullo", "ruoli", "ruolo", "ruota", "ruote", "ruoto", "rupia", "rupie", "ruppi", "ruspa", "ruspe", "ruspi", "ruspo", "russa", "russe", "russi", "russo", "rutta", "rutti", "rutto", "sacca", "sacco", "sacra", "sacre", "sacri", "sacro", "sagge", "saggi", "sagra", "sagre", "salda", "salde", "saldi", "saldo", "salma", "salme", "salmi", "salmo", "salpa", "salpi", "salpo", "salsa", "salse", "salta", "salti", "salto", "salva", "salve", "salvi", "salvo", "samba", "sanai", "santa", "sante", "santi", "santo", "sarai", "sarda", "sarde", "sardi", "sardo", "sarei", "sarta", "sarto", "sassi", "sasso", "sauna", "sauro", "savio", "sazia", "sazio", "sbafo", "sbava", "sbavi", "sbavo", "sbuca", "sbuco", "scada", "scade", "scadi", "scado", "scafi", "scafo", "scala", "scale", "scali", "scalo", "scava", "scavi", "scavo", "scema", "scena", "scesa", "scese", "scesi", "sceso", "scoli", "scolo", "scoop", "scopa", "scope", "scopi", "scopo", "score", "scout", "scova", "scovi", "scovo", "scudi", "scudo", "scuoi", "scura", "scure", "scuri", "scuro", "scusa", "scuse", "scusi", "scuso", "sdrai", "sdram", "secca", "secco", "sedai", "sedia", "sedie", "seggi", "seghe", "seghi", "segna", "segni", "segno", "segua", "segue", "segui", "seguo", "selce", "selci", "sella", "selle", "selli", "sello", "selva", "selve", "senno", "sensi", "senso", "senta", "sente", "senti", "sento", "senza", "serba", "serbe", "serbi", "serbo", "seria", "serie", "serio", "serpe", "serpi", "serra", "serre", "serri", "serro", "serva", "serve", "servi", "servo", "sesso", "sesta", "sesto", "setta", "sette", "setto", "sfama", "sfami", "sfamo", "sfasa", "sfasi", "sfaso", "sfera", "sfere", "sfida", "sfide", "sfidi", "sfido", "sfiga", "sfila", "sfili", "sfilo", "sfizi", "sfoci", "sfoga", "sfogo", "sfora", "sfori", "sforo", "sfuso", "sgama", "sgami", "sgamo", "sgasa", "sgasi", "sgaso", "sgela", "sgeli", "sgelo", "share", "shift", "shoah", "shock", "siamo", "siano", "siate", "sidro", "siena", "siepe", "siepi", "siero", "siete", "sigla", "sigli", "siglo", "sigma", "silio", "silva", "sinai", "siria", "sisma", "sismi", "skill", "slama", "slami", "slamo", "slava", "slavo", "slega", "slego", "slide", "sloga", "slogo", "smart", "smise", "smisi", "snack", "snida", "snidi", "snido", "snoda", "snodi", "snodo", "snort", "soave", "sobri", "socio", "sodio", "soffi", "sofia", "sogna", "sogni", "sogno", "solca", "solco", "soldi", "soldo", "solfa", "solfi", "solfo", "somma", "somme", "sommi", "sommo", "sonar", "sonda", "sonde", "sondi", "sondo", "sonia", "sonni", "sonno", "sopii", "sopra", "sorbo", "sorci", "sordo", "sorga", "sorge", "sorgi", "sorgo", "sorse", "sorsi", "sorso", "sorta", "sorte", "sorti", "sorto", "sosia", "sosta", "soste", "sosti", "sosto", "sotto", "sotto", "sound", "spada", "spade", "spago", "spaia", "spaio", "spala", "spana", "spani", "spano", "spara", "spari", "sparo", "spazi", "speck", "speme", "spemi", "spera", "speri", "spero", "spesa", "spese", "spesi", "speso", "spiga", "spigo", "spina", "spine", "spini", "spino", "spira", "spire", "spiro", "spore", "sport", "sposa", "spose", "sposi", "sposo", "spray", "spuma", "spumi", "spumo", "sputa", "sputi", "sputo", "stadi", "staff", "stage", "stand", "stani", "stano", "stasi", "stati", "stato", "stele", "steli", "stelo", "stesa", "stese", "stesi", "steso", "stick", "stila", "stile", "stima", "stimi", "stimo", "stipa", "stipe", "stipi", "stipo", "stira", "stiri", "stiro", "stiva", "stive", "stivi", "stivo", "stock", "stona", "stoni", "stono", "studi", "stufa", "stufi", "stufo", "stura", "sturi", "sturo", "succo", "sudai", "sudan", "suide", "suina", "suine", "suini", "suino", "suite", "sulla", "suola", "suole", "suoli", "suolo", "suona", "suoni", "suono", "suora", "suore", "super", "surfa", "surfo", "sushi", "svaga", "svago", "svapo", "svela", "svelo", "svevo", "svita", "sviti", "svito", "swing", "tacci", "tacco", "tagli", "taiga", "talco", "talpa", "talpe", "tanfi", "tanfo", "tanga", "tango", "tante", "tanti", "tanto", "tappa", "tappe", "tappi", "tappo", "tarai", "tarda", "tarde", "tardi", "tardo", "targa", "targo", "tasca", "tassa", "tasse", "tassi", "tasso", "tasta", "tasti", "tasto", "tatto", "tatua", "tatui", "tatuo", "tauto", "tazza", "tazze", "tedia", "tedio", "telai", "tempi", "tempo", "tenda", "tende", "tendi", "tendo", "tenga", "tengo", "tenne", "tenni", "tenta", "tenti", "tento", "tenue", "tenui", "teoro", "terme", "termo", "terni", "terno", "terra", "terre", "tersa", "terse", "tersi", "terso", "terza", "terze", "terzi", "terzo", "tesla", "tessa", "testa", "teste", "testi", "testo", "tetra", "tetre", "tetri", "tetro", "tetti", "tetto", "texas", "tiara", "tiare", "tibia", "tibie", "tiene", "tieni", "tifai", "tigna", "tigre", "tigri", "tilde", "timer", "tinga", "tinge", "tingi", "tingo", "tinse", "tinsi", "tinta", "tinte", "tinti", "tinto", "tioli", "tiolo", "tirai", "tirio", "tirso", "tizio", "toast", "tobia", "tocca", "tocco", "toghe", "togli", "tokyo", "tolga", "tolgo", "tolse", "tolsi", "tolta", "tolte", "tolti", "tolto", "tomba", "tombe", "tonda", "tonde", "tondo", "tonfa", "tonfi", "tonfo", "tonni", "tonno", "tonto", "toppa", "toppe", "toppi", "toppo", "torba", "torbe", "torbo", "torca", "torce", "torna", "torni", "torno", "torre", "torri", "torse", "torsi", "torso", "torta", "torte", "torti", "torto", "torvo", "tosai", "tosca", "tosse", "tosta", "tosti", "tosto", "totem", "tozza", "tozze", "tozzi", "tozzo", "trace", "traci", "trama", "trame", "trami", "tramo", "trani", "trans", "trave", "travi", "trema", "tremi", "tremo", "trend", "treni", "treno", "triti", "trito", "troia", "troll", "troni", "trono", "trota", "trote", "trova", "trovi", "trovo", "truce", "trust", "tubai", "tuffa", "tuffi", "tuffo", "tuona", "tuoni", "tuono", "turba", "turbi", "turbo", "turca", "turco", "turpe", "turpi", "tutor", "tutta", "tutte", "tutti", "tutto", "tweet", "ubica", "ubico", "ubini", "udine", "udito", "uggia", "uliva", "ulivo", "ultra", "ulula", "ululi", "ululo", "umana", "umane", "umani", "umano", "umbra", "umbro", "umida", "umide", "umidi", "umido", "umile", "umili", "umore", "umori", "unica", "unici", "unico", "unita", "uniti", "unito", "univa", "univi", "univo", "upupa", "urali", "urano", "urina", "urine", "urini", "urino", "urlai", "urtai", "usano", "usata", "usate", "usati", "usato", "usava", "usavi", "usavo", "uscio", "usino", "usura", "usuri", "usuro", "uteri", "utero", "utile", "utili", "vacai", "vacca", "vachi", "vacuo", "vagai", "vaghe", "vaghi", "valgo", "valle", "valli", "vallo", "vanga", "vango", "vania", "vanni", "vanta", "vanti", "vanto", "varca", "varco", "varia", "varie", "vario", "vasai", "vasca", "vasco", "vasta", "vaste", "vasti", "vasto", "vegan", "velai", "velma", "venda", "vende", "vendi", "vendo", "venga", "vengo", "venia", "venir", "venne", "venni", "venti", "vento", "verbi", "verbo", "verde", "verdi", "verga", "verme", "vermi", "versa", "versi", "verso", "verza", "vespa", "vespe", "vessa", "vessi", "vesso", "veste", "vesti", "vesto", "vetri", "vetro", "vetta", "vette", "vezzi", "vezzo", "viale", "viali", "vibra", "vibri", "vibro", "video", "viene", "vieni", "vieri", "vieta", "vieti", "vieto", "vigna", "vigne", "villa", "ville", "vinca", "vince", "vinci", "vinco", "vinse", "vinsi", "vinta", "vinte", "vinti", "vinto", "viola", "viole", "violi", "violo", "virai", "virus", "visse", "vissi", "vista", "viste", "visti", "visto", "vitto", "vivia", "vizia", "vizio", "vizzi", "vizzo", "vocai", "vocia", "vocio", "vodka", "vogai", "voghi", "volai", "volga", "volge", "volgi", "volgo", "volpa", "volpe", "volpi", "volpo", "volse", "volsi", "volta", "volte", "volti", "volto", "votai", "vuota", "vuoti", "vuoto", "wafer", "wanda", "water", "yacht", "yemen", "zaini", "zaino", "zaira", "zampa", "zampe", "zampi", "zampo", "zanna", "zanne", "zappa", "zappi", "zappo", "zebra", "zebre", "zecca", "zenit", "zenon", "zeppa", "zeppe", "zeppi", "zeppo", "zifio", "zinca", "zinco", "zippa", "zippi", "zippo", "zitta", "zitte", "zitti", "zitto", "zizza", "zolfo", "zolla", "zolle", "zombi", "zompa", "zompi", "zompo", "zonzo", "zoppo", "zorro", "zucca", "zuffa", "zuffe", "zuppa", "zuppe", "zuppo"};
    int c = 0; /* Contatore del numero di parole immesse dal giocatore */
    int j = 0;
    int flag = 0; /* flag per ripetere la richiesta della parola nel caso la parola immessa fosse di lunghezza diversa da 5 o se ci fossero dei caratteri speciali */
    int i = 0;
    int cont[26]; /* contatore delle lettere nella parola da indovinare */
    int tmp[26]; /* variabile temporanea per la funzione checkLetterYellow che contiene una copia dei valori persenti in cont */
    char scelta;
    char parolaInput[MAXTRY][MAXTRY]; /* inizializzazione delle parole che inserisce l'utente */
    char indovina[MAXTRY]; /* variabile che contiene la parola da indovinare */
    char tmpStr[MAXTRY];

    srand (time (0));

    textcolor (WHITE);

    printf("\n(_)           (_)    (_)(_)(_)(_)    (_)(_)(_)(_)      (_)(_)(_)(_)      (_)               (_)(_)(_)(_)  ");
    printf("\n(_)           (_)  (_)          (_)  (_)         (_)    (_)       (_)    (_)               (_)               ");
    printf("\n(_)           (_)  (_)          (_)  (_)         (_)    (_)        (_)   (_)               (_)           ");
    printf("\n(_)    (_)    (_)  (_)          (_)  (_)(_)(_)(_)       (_)        (_)   (_)               (_)(_)(_)         ");
    printf("\n(_)  (_) (_)  (_)  (_)          (_)  (_)   (_)          (_)        (_)   (_)               (_)               ");
    printf("\n(_) (_)   (_) (_)  (_)          (_)  (_)      (_)       (_)       (_)    (_)               (_)    ");
    printf("\n  (_)       (_)      (_)(_)(_)(_)    (_)         (_)   (_)(_)(_)(_)      (_)(_)(_)(_)(_)   (_)(_)(_)(_)   ");

    /* Opizone per visualizzare le regle del gioco */
    do {
        printf("\n\nVuoi consultare le regole del gioco (s/n)? ");
        scelta = getchar();
        while (getchar() != '\n');
        scelta = tolower (scelta);
    }while (scelta != 's' && scelta != 'n');

    if (scelta == 's') {
        printf("\nWorlde prevede di far indovinare una parola misteriosa di 5 lettere al giocatore.");
        printf("\nSi avranno a disposizione al massimo sei tentativi e si dovra' provare ad arrivare alla parola misteriosa inserendo altre parole.");
        printf("\n\nDopo aver eseguito uno dei tentativi, la parola inserita verra' mostrata attraverso l'utilizzo di 3 colori principali:");
        printf("\n1. BIANCO - La lettera non e' presente nella parola misteriosa.");
        printf("\n2.");
        textcolor (YELLOW);
        printf(" GIALLO ");
        textcolor (WHITE);
        printf("- La lettera e' presente nella parola da indovinare ma e' stata inserita nella posizione sbagliata nel tentativo.");
        printf("\n3.");
        textcolor (LIGHTGREEN);
        printf(" VERDE ");
        textcolor (WHITE);
        printf(" - La lettera e' presente nella parola da indovinare ed e' anche stata inserita nella posizione corretta. ");
        printf("\n\nEsempio:");
        printf("\nParola da indovinare: palla");
        printf("\nTentativo 1: lesta");
        printf("\n%c", 218);
        for (j = 0; j < MAXTRY - 1; j++) {
            for (i = 0; i < 3; i++) {
                printf("%c", 196);
            }
            printf("%c", 194);
        }
        printf("\b%c", 191);
        printf("\n%c", 179);
        textcolor (YELLOW);
        printf(" l ");
        textcolor (WHITE);
        printf("%c e %c s %c t %c ", 179, 179, 179, 179);
        textcolor (LIGHTGREEN);
        printf("a ");
        textcolor (WHITE);
        printf("%c", 179);
        printf("\n%c", 192);
        for (j = 0; j < MAXTRY - 1; j++) {
            for (i = 0; i < 3; i++) {
                printf("%c", 196);
            }
            printf("%c", 193);
        }
        printf("\b%c", 217);

        printf("\n\n\nPremere un tasto per giocare");
        getch ();
    }

    do {
        clrscr ();
        c = 0;
        for (i = 0; i < MAXTRY; i++) {
            for (j = 0; j < MAXTRY; j++)
                parolaInput[i][j] = ' ';
        }

        /* procedura per scegliere la parola da indovinare in modo pseudo-randomico */
        randomWord (matWord, indovina);

        /* procedura per stampare la tabella vuota (in questo caso) */
        stampaTabella (indovina, parolaInput, c, cont, tmp);

        while (c < MAXTRY && strcmp (parolaInput[c - 1], indovina) != 0) {
            /* inizializzazione di cont */
            for (i = 0; i < 26; i++) {
                cont[i] = 0;
            }

            do {
                flag = 0;

                /* richiesta parola in input */
                printf("\nIndovina la parola: ");
                scanf ("%s", parolaInput[c]);

                for (i = 0; i < MAXTRY - 1; i++) {
                    tmpStr[i] = parolaInput[c][i];
                }

                /* verifica se la parola immessa e' di lunghezza pari a 5) */
                if (strlen (parolaInput[c]) != 5) {
                    for (j = 5; j < 36; j++) {
                        parolaInput[c][j] = ' ';
                    }

                    for (j = 0; j < 5; j++)
                        parolaInput[c][j] = ' ';

                    flag = 1;
                }

                /* verfica se la parola immessa contiene caratteri speciali */
                for (j = 0; j < MAXTRY - 1; j++) {
                    parolaInput[c][j] = tolower (parolaInput[c][j]);
                    tmpStr[j] = tolower (tmpStr[j]);
                    if ( (tmpStr[j] < 'a' || tmpStr[j] > 'z') && tmpStr[j] != ' ') {
                        flag = 1;
                    }
                }

                if (flag == 1) {
                    printf("\nLa parola inserita contiene caratteri non alfabetici o non e' composta da 5 caratteri.");
                }

            } while (strlen (parolaInput[c]) != 5 || flag == 1);

            /* pulisce lo schermo da tutte le scritte */
            clrscr ();

            /* cont viene aumentato nelle celle corrispondenti alle lettere alfabetiche (dato che 'a' = 97 se si toglie 97 dalla lettera che stiamo prendendo in considerazione per metterla nella cella corrispondente in cont) */
            for (i = 0; i < MAXTRY - 1; i++) {
                cont[indovina[i] - 97] += 1;
            }

            /* copia di cont in tmp */
            for (i = 0; i < 26; i++) {
                tmp[i] = cont[i];
            }

            /* stampa della tabella comprese le parole inserite dall'utente */
            stampaTabella (indovina, parolaInput, c, cont, tmp);

            c++;
        }

        /* verifica se hai indovinato la parola o meno */
        if (strcmp (parolaInput[c - 1], indovina) != 0) {
            printf("\nPeccato hai perso! La parola da trovare era %s\n\n", indovina);
        }else {
            printf("\nComplimenti! Hai trovato la parola corretta\n\n");
        }

        /* Opzione per giocare nuovamente */
        do {
            printf("\nVuoi giocare di nuovo (s/n)? ");
            while (getchar () != '\n');
            scanf ("%c", &scelta);
            scelta = tolower (scelta);
        }while (scelta != 's' && scelta != 'n');
    }while (scelta == 's');

    printf("\n\nPremere un tasto qualsiasi per terminare il programma.");
    getch ();

    return 0;
}

