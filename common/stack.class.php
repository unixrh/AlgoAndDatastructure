<?php
class Stack {
  protected $stackArr = array();
  protected $limit;
  protected $size = 0;
  public function __construct($limit) {
    $this->limit = $limit;
  }

  public function size(){
    return $this->size;
  }

  public function limit(){
    return $this->limit;
  }

  public function push($item) {
    if($this->size < $this->limit) {
      $this->stackArr[$this->size] = $item;
      $this->size++;
    } else {
      echo "stack full \n";
    }
  }

  public function pop() {
    if($this->size == 0) {
      echo "stack empty \n";
    } else {
      $this->size--;
    }
  }

  public function top() {
    if($this->size == 0) {
      echo "stack empty \n";
    } else {
      return $this->stackArr[$this->size - 1];
    }
  }

  public function isEmpty() {
    return $this->size <= 0;
  }
}
?>
