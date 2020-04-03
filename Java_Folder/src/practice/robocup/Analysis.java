package src.practice.robocup;

public class Analysis {
    public static void main(String[] args) {
        String Hear = "hear";
        String See = "see";
        String Ball_ = "ball";
        String Goal_ = "goal";
        String Line_ = "line";
        String Flag_ = "flag";
        String Player_ = "player";
        String msg = "(hear 1022 -30 passto(23,24))(see 1022 ((ball) 20 -20 1 -2) ((player hfut1 2) 23 45 0.5 1 22 40 ) ((goal r) 12 20))";
        
        int i;

        if (msg.contains(See)) {
            i = 0;
            while (i < msg.length()) {
                if (msg.charAt(i) == 's' && msg.charAt(i + 1) == 'e' && msg.charAt(i + 2) == 'e') {
                    if (msg.charAt(i) == 'h' && msg.charAt(i + 1) == 'e' && msg.charAt(i + 2) == 'a' && msg.charAt(i + 3) == 'r') {
                        break;
                    }

                    String Time_ = "";

                    while (msg.charAt(i) != ' ') {
                        i++;
                    }
                    i++;
                    while (msg.charAt(i) != ' ') {
                        Time_ += msg.charAt(i);
                        i++;
                    }

                    while (msg.charAt(i) != 'b' && msg.charAt(i + 1) != 'a' && msg.charAt(i + 2) != 'l' && msg.charAt(i + 3) != 'l') {
                        i++;
                    }
                    i++;
                    i = msg.indexOf("ball", i);

                    if (i == -1) {
                        break;
                    }

                    if (msg.charAt(i) == 'b' && msg.charAt(i + 1) == 'a' && msg.charAt(i + 2) == 'l' && msg.charAt(i + 3) == 'l') {
                        String Distance_ = "";
                        String Direction_ = "";
                        String DistChng_ = "";
                        String DirChng_ = "";

                        while (msg.charAt(i) != ' ') {
                            i++;
                        }
                        i++;
                        while (msg.charAt(i) != ' ') {
                            Distance_ += msg.charAt(i);
                            i++;
                        }

                        while (msg.charAt(i) != ' ') {
                            i++;
                        }
                        i++;
                        while (msg.charAt(i) != ' ') {
                            Direction_ += msg.charAt(i);
                            i++;
                        }

                        while (msg.charAt(i) != ' ') {
                            i++;
                        }
                        i++;
                        while (msg.charAt(i) != ' ') {
                            DistChng_ += msg.charAt(i);
                            i++;
                        }

                        while (msg.charAt(i) != ' ') {
                            i++;
                        }
                        i++;
                        while (msg.charAt(i) != ')') {
                            DirChng_ += msg.charAt(i);
                            i++;
                        }

                        Ball ball = new Ball(Time_, Distance_, Direction_, DistChng_, DirChng_);

                        System.out.println("在 " + ball.getTime_Period() + " 周期 see " + Ball_ + "距离我的 Distance 是 " + ball.getDistance() + ", Direction 是 " + ball.getDirection() + ", DistChng 是 " + ball.getDistChng() + ", DirChng 是 " + ball.getDirChng() + "; ");
                    
                    }
                    break;
                }
                i++;
            }
        }
        
        if (msg.contains(See)) {
            i = 0;
            while (i < msg.length()) {
                if (msg.charAt(i) == 's' && msg.charAt(i + 1) == 'e' && msg.charAt(i + 2) == 'e') {
                    if (msg.charAt(i) == 'h' && msg.charAt(i + 1) == 'e' && msg.charAt(i + 2) == 'a' && msg.charAt(i + 3) == 'r') {
                        break;
                    }

                    String Time_ = "";

                    while (msg.charAt(i) != ' ') {
                        i++;
                    }
                    i++;
                    while (msg.charAt(i) != ' ') {
                        Time_ += msg.charAt(i);
                        i++;
                    }

                    while (msg.charAt(i) != 'g' && msg.charAt(i + 1) != 'o' && msg.charAt(i + 2) != 'a' && msg.charAt(i + 3) != 'l') {
                        i++;
                    }
                    i = msg.indexOf("goal", i);

                    if (i == -1) {
                        break;
                    }

                    if (msg.charAt(i) == 'g' && msg.charAt(i + 1) == 'o' && msg.charAt(i + 2) == 'a' && msg.charAt(i + 3) == 'l') {
                        String Distance_ = "";
                        String Direction_ = "";
                        String Name_ = "";
                        i += 5;

                        while (msg.charAt(i) != ')') {
                            Name_ += msg.charAt(i);
                            i++;
                        }

                        while (msg.charAt(i) != ' ') {
                            i++;
                        }
                        i++;
                        while (msg.charAt(i) != ' ') {
                            Distance_ += msg.charAt(i);
                            i++;
                        }

                        while (msg.charAt(i) != ' ') {
                            i++;
                        }
                        i++;
                        while (msg.charAt(i) != ')') {
                            Direction_ += msg.charAt(i);
                            i++;
                        }

                        Goal goal = new Goal(Time_, Name_, Distance_, Direction_);

                        System.out.println(Goal_ + " " + goal.getName() + "距离我的 Distance 是 " + goal.getDistance() + ", Direction 是 " + goal.getDirection() + "; ");
                    }
                    break;
                }
                i++;
            }    
        }
        
        if (msg.contains(See)) {
            i = 0;
            while (i < msg.length()) {
                if (msg.charAt(i) == 's' && msg.charAt(i + 1) == 'e' && msg.charAt(i + 2) == 'e') {
                    if (msg.charAt(i) == 'h' && msg.charAt(i + 1) == 'e' && msg.charAt(i + 2) == 'a' && msg.charAt(i + 3) == 'r') {
                        break;
                    }

                    String Time_ = "";

                    while (msg.charAt(i) != ' ') {
                        i++;
                    }
                    i++;
                    while (msg.charAt(i) != ' ') {
                        Time_ += msg.charAt(i);
                        i++;
                    }

                    while (msg.charAt(i) != 'l' && msg.charAt(i + 1) != 'i' && msg.charAt(i + 2) != 'n' && msg.charAt(i + 3) != 'e') {
                        i++;
                    }
                    i++;
                    i = msg.indexOf("line", i);

                    if (i == -1) {
                        break;
                    }

                    if (msg.charAt(i) == 'l' && msg.charAt(i + 1) == 'i' && msg.charAt(i + 2) == 'n' && msg.charAt(i + 3) == 'e') {
                        String Distance_ = "";
                        String Direction_ = "";
                        String Name_ = "";

                        i += 5;

                        while (msg.charAt(i) != ')') {
                            Name_ += msg.charAt(i);
                            i++;
                        }

                        while (msg.charAt(i) != ' ') {
                            i++;
                        }
                        i++;
                        while (msg.charAt(i) != ' ') {
                            Distance_ += msg.charAt(i);
                            i++;
                        }

                        while (msg.charAt(i) != ' ') {
                            i++;
                        }
                        i++;
                        while (msg.charAt(i) != ')') {
                            Direction_ += msg.charAt(i);
                            i++;
                        }

                        while (msg.charAt(i) != ' ') {
                            i++;
                        }

                        Line line = new Line(Time_, Name_, Distance_, Direction_);

                        System.out.println(Line_ + " " + line.getName() + "距离我的 Distance 是 " + line.getDistance() + ", Direction 是 " + line.getDirection() + "; ");
                    }
                    break;
                }
                i++;
            }
        }
        
        if (msg.contains(See)) {
            i = 0;
            while (i < msg.length()) {
                if (msg.charAt(i) == 's' && msg.charAt(i + 1) == 'e' && msg.charAt(i + 2) == 'e') {
                    if (msg.charAt(i) == 'h' && msg.charAt(i + 1) == 'e' && msg.charAt(i + 2) == 'a' && msg.charAt(i + 3) == 'r') {
                        break;
                    }

                    String Time_ = "";

                    while (msg.charAt(i) != ' ') {
                        i++;
                    }
                    i++;
                    while (msg.charAt(i) != ' ') {
                        Time_ += msg.charAt(i);
                        i++;
                    }

                    while (msg.charAt(i) != 'f') {
                        i++;
                    }
                    i++;
                    i = msg.indexOf("f", i);

                    if (i == -1) {
                        break;
                    }

                    if (msg.charAt(i) == 'f') {
                        String Distance_ = "";
                        String Direction_ = "";
                        String Name_ = "";

                        i += 2;

                        while (msg.charAt(i) != ')') {
                            Name_ += msg.charAt(i);
                            i++;
                        }

                        while (msg.charAt(i) != ' ') {
                            i++;
                        }
                        i++;
                        while (msg.charAt(i) != ' ') {
                            Distance_ += msg.charAt(i);
                            i++;
                        }

                        while (msg.charAt(i) != ' ') {
                            i++;
                        }
                        i++;
                        while (msg.charAt(i) != ')') {
                            Direction_ += msg.charAt(i);
                            i++;
                        }

                        while (msg.charAt(i) != ' ') {
                            i++;
                        }

                        Flag flag = new Flag(Time_, Name_, Distance_, Direction_);

                        System.out.println(Flag_ + " " + flag.getName() + "距离我的 Distance 是 " + flag.getDistance() + ", Direction 是 " + flag.getDirection() + "; ");
                    }
                }
                break;
            }
            i++;
        }
        
        if (msg.contains(See)) {
            i = 0;
            while (i < msg.length()) {
                if (msg.charAt(i) == 's' && msg.charAt(i + 1) == 'e' && msg.charAt(i + 2) == 'e') {
                    if (msg.charAt(i) == 'h' && msg.charAt(i + 1) == 'e' && msg.charAt(i + 2) == 'a' && msg.charAt(i + 3) == 'r') {
                        break;
                    }

                    String Time_ = "";

                    while (msg.charAt(i) != ' ') {
                        i++;
                    }
                    i++;
                    while (msg.charAt(i) != ' ') {
                        Time_ += msg.charAt(i);
                        i++;
                    }

                    while (msg.charAt(i) != 'p' && msg.charAt(i + 1) != 'l' && msg.charAt(i + 2) != 'a' && msg.charAt(i + 3) != 'y' 
                    && msg.charAt(i + 2) != 'a' && msg.charAt(i + 3) != 'y' && msg.charAt(i + 4) != 'e' && msg.charAt(i + 5) != 'r') {
                        i++;
                    }
                    i++;
                    i = msg.indexOf("player", i);

                    if (i == -1) {
                        break;
                    }

                    if (msg.charAt(i) == 'p' && msg.charAt(i + 1) == 'l' && msg.charAt(i + 2) == 'a' && msg.charAt(i + 3) == 'y' && msg.charAt(i + 4) == 'e' && msg.charAt(i + 5) == 'r') {
                        String Distance_ = "";
                        String Direction_ = "";
                        String DistChng_ = "";
                        String DirChng_ = "";
                        String BodyDir_ = "";
                        String HeadDir_ = "";
                        String Name_ = "";

                        i += 7;

                        if (msg.charAt(i) == 'h' && msg.charAt(i + 1) == 'f' && msg.charAt(i + 2) == 'u' && msg.charAt(i + 3) == 't' && msg.charAt(i + 4) == '1') {
                            
                            while (msg.charAt(i) != ' ') {
                                i++;
                            }
                            i++;
                            while (msg.charAt(i) != ')') {
                                Name_ += msg.charAt(i);
                                i++;
                            }
    
                            while (msg.charAt(i) != ' ') {
                                i++;
                            }
                            i++;
                            while (msg.charAt(i) != ' ') {
                                Distance_ += msg.charAt(i);
                                i++;
                            }
    
                            while (msg.charAt(i) != ' ') {
                                i++;
                            }
                            i++;
                            while (msg.charAt(i) != ' ') {
                                Direction_ += msg.charAt(i);
                                i++;
                            }

                            while (msg.charAt(i) != ' ') {
                                i++;
                            }
                            i++;
                            while (msg.charAt(i) != ' ') {
                                DistChng_ += msg.charAt(i);
                                i++;
                            }
    
                            while (msg.charAt(i) != ' ') {
                                i++;
                            }
                            i++;
                            while (msg.charAt(i) != ' ') {
                                DirChng_ += msg.charAt(i);
                                i++;
                            }

                            while (msg.charAt(i) != ' ') {
                                i++;
                            }
                            i++;
                            while (msg.charAt(i) != ' ') {
                                BodyDir_ += msg.charAt(i);
                                i++;
                            }
    
                            while (msg.charAt(i) != ' ') {
                                i++;
                            }
                            i++;
                            while (msg.charAt(i) != ')') {
                                HeadDir_ += msg.charAt(i);
                                i++;
                            }

                            while (msg.charAt(i) != ' ') {
                                i++;
                            }
    
                            Teammate teammate = new Teammate(Name_, Time_, Distance_, Direction_, DistChng_, DirChng_, BodyDir_, HeadDir_);
                            System.out.println(Player_ + " " + teammate.getName() + " 距离我的 Distance 是 " + teammate.getDistance() + ", Direction 是 " 
                            + teammate.getDirection() + ", BodyDir 是 " + teammate.getBodyDir() + ", HeadDir 是 " + teammate.getHeadDir() + "; ");
                        }

                        else if (msg.charAt(i) == 'h' && msg.charAt(i + 1) == 'f' && msg.charAt(i + 2) == 'u' && msg.charAt(i + 3) == 't' && msg.charAt(i + 4) == '2') {
                            
                            while (msg.charAt(i) != ' ') {
                                    i++;
                            }
                            i++;
                            while (msg.charAt(i) != ')') {
                                Name_ += msg.charAt(i);
                                i++;
                            }
        
                            while (msg.charAt(i) != ' ') {
                                i++;
                            }
                            i++;
                            while (msg.charAt(i) != ' ') {
                                Distance_ += msg.charAt(i);
                                i++;
                            }
        
                            while (msg.charAt(i) != ' ') {
                                i++;
                            }
                            i++;
                            while (msg.charAt(i) != ' ') {
                                Direction_ += msg.charAt(i);
                                i++;
                            }
    
                            while (msg.charAt(i) != ' ') {
                                i++;
                            }
                            i++;
                            while (msg.charAt(i) != ' ') {
                                DistChng_ += msg.charAt(i);
                                i++;
                            }
        
                            while (msg.charAt(i) != ' ') {
                                i++;
                            }
                            i++;
                            while (msg.charAt(i) != ' ') {
                                DirChng_ += msg.charAt(i);
                                i++;
                            }
    
                            while (msg.charAt(i) != ' ') {
                                i++;
                            }
                            i++;
                            while (msg.charAt(i) != ' ') {
                                BodyDir_ += msg.charAt(i);
                                i++;
                            }
        
                            while (msg.charAt(i) != ' ') {
                                i++;
                            }
                            i++;
                            while (msg.charAt(i) != ')') {
                                HeadDir_ += msg.charAt(i);
                                i++;
                            }

                            while (msg.charAt(i) != ' ') {
                                i++;
                            }
        
                            Opponent opponent = new Opponent(Time_, Name_, Distance_, Direction_, DistChng_, DirChng_, BodyDir_, HeadDir_);
        
                            System.out.println(Player_ + " " + opponent.getName() + " 距离我的 Distance 是 " + opponent.getDistance() + ", Direction 是 " +
                             opponent.getDirection() + ", BodyDir 是 " + opponent.getBodyDir() + ", HeadDir 是 " + opponent.getHeadDir() + "; ");
                        }
                    }
                    break;
                }
                i++;
            }
        }

        if (msg.contains(Hear)) {
            String Time_ = "";
            String Dir_ = "";
            String message_ = "";

            for (i = 0; i < msg.length() - 4; i++) {
                if (msg.charAt(i) == 'h' && msg.charAt(i + 1) == 'e' && msg.charAt(i + 2) == 'a' && msg.charAt(i + 3) == 'r') {
                    if (msg.charAt(i) == 's' && msg.charAt(i + 1) == 'e' && msg.charAt(i + 2) == 'e') {
                        break;
                    }

                    while (msg.charAt(i) != ' ') {
                        i++;
                    }
                    i++;
    
                    while (msg.charAt(i) != ' ') {
                        Time_ += msg.charAt(i);
                        i++;
                    }
    
                    while (msg.charAt(i) != ' ') {
                        i++;
                    }
                    i++;
    
                    while (msg.charAt(i) != ' ') {
                        Dir_ += msg.charAt(i);
                        i++;
                    }
    
                    while (msg.charAt(i) != ' ') {
                        i++;
                    }
                    i++;
    
                    while (msg.charAt(i) != ')') {
                        message_ += msg.charAt(i);
                        i++;
                    }
                    message_ += ")";
                    i++;

                    System.out.println("在 " + Time_ + " 周期 hear 从 " + Dir_ + " 方向听到了 " + message_ + "; ");
                }
            }
        }
    }
}