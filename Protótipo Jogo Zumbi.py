#SILVIA BEATRIZ PEREIRA DE SOUSA // ANALISE E DESENVOLVIMENTO DE SISTEMAS - EAD // ATIVIDADE SOMATIVA 1
import random 
from re import T
from xml.etree.ElementTree import QName 
''' Mensagem amistosa de boas vindas'''
print("BEM VINDO A ZOMBIE DICE!!!", end= '\n\n\n')
print("PARA JOGAR COLOQUE A QUANTIDADE DE JOGADORES!!", end= '\n\n\n') 

#Bloco de barramento de 1 ou menos jogadores
jogadores = int(input("DIGITE: ")) 
rodadas=0 
for rodadas in range(jogadores): 
  print('\n') 
  print("RODADA: ",rodadas+1, end= '\n\n') 
  while jogadores <= 1: 
        print("Para jogar Zombie Dice é necessário 2 ou mais jogadores!") 
        jogadores = int(input("Digite a quantidade de jogadores: ")) 
        continue 
  jogar = str(input("É hora de rolar os dados! Digite sim para continuar: ")) 
  print("\n") 
  while jogar != "sim": 
    print("Quando estiver preparado, pode rolar os dados!") 
    jogar = str(input("É hora de rolar os dados! Digite sim para continuar: ")) 
    continue
  
  qnt_cerebro = 0 
  qnt_tiro = 0
  qnt_passos = 0

  rodada1 = 0 
  for rodada1 in range(3): 
    dado1 = random.randint(1,13) 
    if dado1 <=3: 
      dado_vermelho = dado1 
      face_dado1 = random.choice("TPTCPT") 
      if face_dado1 == "T": 
        espingarda = face_dado1 
        qnt_tiro+=1 
        print("Sua vítima revidou!") 
      elif face_dado1 == "C": 
        cerebro = face_dado1 
        qnt_cerebro+=1 
        print("Você devorou o cérebro de sua vítima.") 
      else:
        passos = face_dado1 
        qnt_passos+=1 
        print("Sua vítima escapou!") 
    elif dado1 >=8: 
      dado_verde = dado1 
      face_dado1 = random.choice("CPCTPC") 
      if face_dado1 == "C": 
        cerebro = face_dado1 
        qnt_cerebro+=1 
        print("Você devorou o cérebro de sua vítima.") 
      elif face_dado1 =="T": 
        espingarda = face_dado1 
        qnt_tiro+=1 
        print("Sua vítima revidou!") 
      else:
        passos = face_dado1 
        qnt_passos+=1 
        print("Sua vítima escapou!")
    else:
      dado_amarelo = dado1 
      face_dado1 = random.choice("TPCTPC") 
      if face_dado1 =="C":
        cerebro = face_dado1
        qnt_cerebro+=1 
        print("Você devorou o cérebro de sua vítima.")
      elif face_dado1 =="T":
        espingarda = face_dado1
        qnt_tiro+=1 
        print("Sua vítima revidou!") 
      else:
        passos = face_dado1
        qnt_passos+=1 
        print("Sua vítima escapou!") 
  pass
  print("Cerebros: ",qnt_cerebro) 
  print("Tiros: ",qnt_tiro)
  print("Passos: ",qnt_passos)
pass

    