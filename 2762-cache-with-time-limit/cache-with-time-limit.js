var TimeLimitedCache = function() {
    this.cache = new Map();
};

TimeLimitedCache.prototype.set = function(key, value, duration) {
    const now = Date.now();
    const exists = this.cache.has(key) && this.cache.get(key).expiry > now;

    this.cache.set(key, {
        value: value,
        expiry: now + duration
    });

    return exists;
};

TimeLimitedCache.prototype.get = function(key) {
    const now = Date.now();
    if (!this.cache.has(key)) return -1;

    const item = this.cache.get(key);
    if (item.expiry <= now) {
        this.cache.delete(key);
        return -1;
    }
    return item.value;
};

TimeLimitedCache.prototype.count = function() {
    const now = Date.now();
    let cnt = 0;

    for (const [key, item] of this.cache) {
        if (item.expiry > now) cnt++;
        else this.cache.delete(key);
    }

    return cnt;
};
