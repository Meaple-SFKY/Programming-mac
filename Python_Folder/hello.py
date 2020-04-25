#! python3
market_2nd={'ns':'green','ew':'red'} #ns南北向，ew东西向
 
def switchLights(stoplight):
    for key in stoplight.keys():
        if stoplight[key]=='green':
            stoplight[key]='yellow'
        elif stoplight[key]=='yellow':
            stoplight[key]='red'
        elif stoplight[key]=='red':
            stoplight[key]='green'
    assert 'red' in stoplight.values(),'交通灯都不是红色的'+str(stoplight)
switchLights(market_2nd)
print(market_2nd)
switchLights(market_2nd)
print(market_2nd)
switchLights(market_2nd)
print(market_2nd)