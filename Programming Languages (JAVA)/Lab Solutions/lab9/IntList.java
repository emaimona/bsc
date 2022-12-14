
class IntList {
    private int[] data;
    private int currentSize, maxSize;

    public IntList(int maxSize) {
        data = new int[maxSize];
        this.maxSize = maxSize;
    }

    public void add(int item) { //add an item to the IntList
        if (currentSize == maxSize) {
            throw new IllegalStateException("the IntList is full, you cannot add another item to it!");
        } else {
            data[currentSize++] = item;
        }
    }

    public void concat(IntList that) {
        if (currentSize + that.currentSize > maxSize) {
            throw new IllegalStateException("IntList is full");
        }
        for (int idx = 0; idx < that.currentSize; ++idx) {
            data[currentSize + idx] = that.data[idx];
        }
        this.currentSize += that.currentSize;
    }

    public void removeItemsGreaterThan(int limit) {
        int[] newData = new int[maxSize];
        int newCurrentSize = 0;

        for (int idx=0; idx < currentSize; ++idx) {
            int item = data[idx];
            if (item <= limit) {
                newData[newCurrentSize++] = item;
            }
        }
        this.data = newData;
        this.currentSize = newCurrentSize;
    }

    @Override
    public String toString() {
        if (currentSize <= 0) {
            return "empty IntList";
        }
        StringBuilder sb = new StringBuilder();
        for (int idx = 0; idx < currentSize; ++idx) {
            int item = data[idx];
            sb.append(item);
            sb.append(",");
        }
        return sb.toString();
    }
}