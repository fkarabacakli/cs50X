function plus(id){
    point = document.getElementById(id);
    number = parseInt(point.innerHTML);
    number ++;
    if (number % 10 === 0) {
        window.alert(`Number is ${number}`)
    }
    point.innerHTML = number;

}

function end(){
    user_1 = document.getElementById("point-1");
    user_2 = document.getElementById("point-2");
    user_1_point = parseInt(user_1.innerHTML);
    user_2_point = parseInt(user_2.innerHTML);
    if (user_1_point === 0 && user_2_point===0){
        window.alert("Game Did Not Start Yet");
    }
    else if (user_1_point > user_2_point){
        window.alert("Team 1 Wonn!");
    }
    else if( user_2_point>user_1_point){
        window.alert("Team 2 Wonn!");
    }
    else{
        window.alert("Game is Tie!")
    }
    user_1.innerHTML = 0;
    user_2.innerHTML = 0;
    return false
}