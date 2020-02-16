#Classes and objects

class time:
    hours=0
    minutes=0
    seconds=0

    def print_Time(self,m='am'):
        print ("{0}:{1}:{2} {3}".format(self.hours,self.minutes,self.seconds,m))

current_time=time()
current_time.hours=4
current_time.minutes=30
current_time.seconds=55
current_time.print_Time('pm')
