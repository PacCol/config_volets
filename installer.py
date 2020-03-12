import os
volets = "Volets_v1.0.0.zip"
print("Bienvenue dans l'installeur de 'Configuration des volets'")
while True:
    chemin_installation = input("Où voulez vous installer le programme ? (chemin avec / à la fin ex: /home/user/Downloads/) : ")
    try:
        os.chdir(chemin_installation)
        break
    except:
        print("Ce chemin est incorrect")
try:
    os.chdir("volets")
    print("Le logiciel est déjà installé. Il va être réinstallé...")
    os.chdir("..")
    os.system("rm -r volets/")
    os.mkdir("volets")
    os.chdir("volets")
except:
    os.mkdir("volets")
    os.chdir("volets")
validation = input("Le programme va être téléchargé. Voulez vous continuer ? O/N : ")
if validation == "O":
    print("Téléchargement...")
    os.system("wget https://inventions.ovh/volets/uploads/" + volets)
    print("Téléchargement terminé.")
    print("Décompression...")
    os.system("unzip " + volets)
    print("Décompression terminée.")
    print("Suppression des fichiers inutiles...")
    os.system("rm " + volets)
    print("Suppression des fichiers inutiles terminée.")
    print("Début de l'installation...")
    distrib = input("Quelle est la commande de votre OS ? apt-get/dnf : ")
    validation = input("Une librairie est necessaire pour installer le logiciel. Acceptez vous de l'installer ? O/N : ")
    if validation == "O":
        print("Installation des librairies...")
        os.system("sudo " + distrib + " install g++")
        print("Cela peut prendre un certain temps...")
        os.system("sudo " + distrib + " install libgtkmm-3.0-dev")
        print("Installation des librairies terminée.")
        os.chdir("configuration_des_volets")
        os.system("pwd")
        os.system("ls")
        print("Compilation...")
        os.system("make")
        print("Compilation terminée.")
        print("Installation terminée.")
        print("Création d'une icône de Bureau...")
        bureau = input("Veuillez entrer le chemin d'accès de votre dossier Bureau : ")
        desktop = "[Desktop Entry]\nType=Link\nName=Configuration des volets\nURL=" + chemin_installation + "volets/configuration_des_volets/main"
        os.chdir(bureau)
        try:
            fichier = open("volets.desktop","r")
            fichier.close()
        except:
            os.system("touch volets.desktop")
        fichier = open("volets.desktop","w")
        fichier.write(desktop)
        fichier.close()
        print("Terminé !")
        print("Vous n'avez plus qu'à lancer le programme depuis votre Bureau !")
        
    
    
