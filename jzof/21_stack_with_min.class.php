<?php
require_once("../common/stack.class.php");
class MinStack extends Stack {
  private $minSt = NULL; // 这个辅助栈的初始化必须放在构造函数中，因为Stack类需要传参来构造确定
  public function __construct($limit) {
    $this->limit = $limit;
    $this->minSt = new Stack($limit);
  }
  public function min() {
    if($this->size == 0) {
      echo "stack empty \n";
    } else {
      return $this->minSt->top();
    }
  }

  public function push($item) {
    if($this->size >= $this->limit) {
      echo "push size: " . $this->size . " push limit: " . $this->limit . "\n";
      echo "stack full \n";
      return;
    }
    $top = $this->min();
    if($item < $top)
      $this->minSt->push($item);
    else 
      $this->minSt->push($top);
    $this->size++;
  }

  // 必须覆盖父类的pop方法，因为需要同步清空minStack
  public function pop() {
    if($this->size == 0) {
      echo "stack empty \n";
    } else {
      $this->minSt->pop();
      $this->size--;
    }
  }
}
define("NUM", 10);
$st = new MinStack(NUM);
$st->pop();
echo $st->top() . "\n";
for($i = 8; $i < NUM+3; $i++) {
  $st->push($i);
  echo "cur min: " . $st->min() . "\n";
}
for($i = 1; $i < NUM+3; $i++) {
  $st->push($i);
  echo "cur min: " . $st->min() . "\n";
}
while(!$st->isEmpty()) {
  echo $st->top() . "\n";
  echo "cur min: " . $st->min() . "\n";
  $st->pop();
}
echo "cur size: " . $st->size() . "\n";
echo "====================\n";
for($i = 8; $i < NUM+3; $i++) {
  $st->push($i);
  echo "cur min: " . $st->min() . "\n";
}
echo "cur size: " . $st->size() . "\n";
while(!$st->isEmpty()) {
  echo $st->top() . "\n";
  echo "cur min: " . $st->min() . "\n";
  $st->pop();
}
?>
